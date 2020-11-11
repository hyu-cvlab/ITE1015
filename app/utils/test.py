from typing import List, Tuple, Any, Union, Dict
from pathlib import Path
from functools import partial
import subprocess
import json
import re

from utils import Utils


def variable_inject(obj: Union[object, dict], tar: str)\
        -> str:
    def getter(key):
        if isinstance(obj, dict):
            return obj.get(key[1:-1], key)
        elif isinstance(obj, object):
            return getattr(obj, key[1:-1], key)

    if isinstance(tar, list):
        return [variable_inject(obj, t) for t in tar]

    target = ''
    while True:
        match = re.search(r'\$([^\s]+?)\$', tar)
        if match is None:
            target = target + tar
            break

        b, e = match.span()
        target = target + tar[:b] + getter(match.group())
        tar = tar[e:]

    return target

class Test:
    def __init__(self, test: dict, variable: dict):
        self.name = 'test-name'
        self.requires = []
        self.command = []
        self.failed = []
        self.expect = False

        self.__dict__.update(test)

        self.requires = self.package(self.requires)
        self.command = self.package(self.command)
        self.failed = self.package(self.failed)

        if not isinstance(self.expect, list):
            self.expect = [self.expect] * len(self.command)

        cwd = getattr(self, 'cwd', '')
        if cwd.startswith('.'):
            setattr(self, 'cwd', f"{variable.get('path_prefix', '')}/{getattr(self, 'cwd')}")

        for key, value in variable.items():
            if not hasattr(self, key):
                setattr(self, key, variable_inject(self, value))
            else:
                setattr(self, key, variable_inject(self, variable_inject(variable, getattr(self, key))))
        
        self.command = list(map(partial(variable_inject, self), self.command))
        
    @staticmethod
    def package(variable: Any)\
            -> List[Any]:
        if not isinstance(variable, list):
            variable = [variable]

        return variable

    def run_handler(self, command_expect: Tuple[str, str])\
            -> Tuple[str, str]:

        command, expect = command_expect
        status, message = True, ''
        try:
            process = subprocess.Popen(command, cwd=getattr(self, 'cwd', ''), shell=True,
                                       stdout=subprocess.PIPE, stderr=subprocess.PIPE)
            outs, errs = process.communicate(timeout=30)
            outs, errs = outs.decode('utf-8').strip(), errs.decode('utf-8').strip()

        except Exception as e:
            outs, errs = 'failed', str(e)

        if isinstance(expect, bool):
            if expect and outs:
                message = outs
            elif not expect and not outs:
                pass
            else:
                status, message = False, f'Error in progress, {outs}//{errs}'
        elif expect == outs:
            message = outs
        else:
            status, message = False, f'Expect "{expect}" but got "{outs}"'
        
        return status, message

    def run(self, *args, **kwargs)\
            -> Tuple[List[str], List[str]]:

        return zip(*map(self.run_handler, zip(self.command, self.expect)))


class TestManager:
    def __init__(self, file: str, variable: dict):
        self.file = file
        with open(self.file) as f:
            self.content = json.load(f)

        self.name = self.content.get('name', 'Test')
        variable = {key: variable_inject(self.content.get('globals', {}), value)
                    for key, value in variable.items()}

        self.tests = {test.name: test for test in 
                      [Test(t, variable) 
                       for t in self.content.get('commands', [])]}
        self.entry = self.content.get('entry', self.tests)
        if not isinstance(self.entry, list):
            self.entry = [self.entry]

        self.results: Dict[Test, Tuple[Tuple[bool, str]]]\
            = {test: None for test in self.tests}

    def run_handler(self, test: Test)\
            -> Tuple[int, str]:

        if isinstance(test, str):
            test = self.tests[test]

        if self.results[test.name] is None:
            any(map(self.run_handler, test.requires))
            self.results[test.name] = tuple(test.run())

            status, *_ = zip(*self.results[test.name])
            if not all(status):
                any(map(self.run_handler, test.failed))

    def run(self, *args, **kwargs)\
            -> List[str]:
        any(map(self.run_handler, self.entry))

        for test, val in self.results.items():
            if val is None:
                self.results[test] = ((True, ), ('not-require', ))

        return self.results


def test(student_id: int, test: None)\
        -> Tuple[int, List[str]]:
    path = Path(Utils.config['path']).joinpath('repositories')
    temp = Path(Utils.config['path']).joinpath('temp', str(student_id))
    temp.mkdir(exist_ok=True, parents=True)

    results = TestManager(test, {
        'assignments': str(Path(Utils.config['path']).joinpath('assignments', '$cwd$').absolute()),
        'uid': str(student_id),
        'path_prefix': f'{path}/$uid$',
        'cwd': f'$path_prefix$/$cwd$',
        'temp': str(temp.absolute()),
    }).run()

    return student_id, results
