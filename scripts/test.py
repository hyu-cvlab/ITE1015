from typing import List
import argparse
from pathlib import Path
from functools import partial
from collections import Counter
from multiprocessing import Pool
import subprocess
import json
import re

import pandas as pd 


class Test:
    def __init__(self, test: dict, variable: dict, verbose: bool = True):
        self.name = 'test-name'
        self.requires = []
        self.command = []
        self.cwd = ''
        self.verbose = verbose

        self.__dict__.update(test)

        if not isinstance(self.requires, list):
            self.requires = [self.requires]

        if not isinstance(self.command, list):
            self.command = [self.command]

        if hasattr(self, 'expect'):
            if not isinstance(self.expect, list):
                self.expect = [self.expect]
        else:
            self.expect = [None] * len(self.command)

        for key, value in variable.items():
            setattr(self, key, self.variable_inject(value))

    def variable_inject(self, command: str):
        while True:
            match = re.search('\$(.+?)\$', command)
            if match is None:
                break
            command = command[:match.start()] + getattr(self, match.group()[1:-1], '') + command[match.end():]

        return command

    def run(self, *args, **kwargs):
        if self.verbose:
            print(f'Test run: {self.name}')

        results = []

        for command, expect in zip(map(self.variable_inject, self.command), self.expect):

            try:
                process = subprocess.Popen(command, cwd=self.cwd, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
                outs, errs = process.communicate(timeout=30)
                outs, errs = outs.decode('utf-8'), errs.decode('utf-8')

            except Exception as e:
                outs, errs = 'Failed', str(e)


            if expect is None:
                results.append(outs)
            else:
                if errs or outs.strip() != expect.strip():
                    return False
                else:
                    results.append('pass')

        return results


class TestManager:
    def __init__(self, file: str, variable: dict, verbose: bool = True):
        self.file = file
        with open(self.file) as f:
            self.content = json.load(f)

        self.name = self.content.get('name', 'Test')
        self.tests = {test.name: test for test in 
                      [Test(t, variable, verbose=verbose) for t in self.content.get('commands', [])]}
        self.results = {test: None for test in self.tests}

        if verbose:
            print(f'Test: {self.name} is loaded')
            print(f'Test includes {len(self.tests)} tests')

    def run_handler(self, test: Test):
        if isinstance(test, str):
            test = self.tests[test]

        if self.results[test.name] is None:
            all(map(self.run_handler, test.requires))
            self.results[test.name] = test.run()

        return True

    def run(self, *args, **kwargs):
        all(map(self.run_handler, self.tests.values()))

        return self.results


def test(student_id, test: None, path: Path = None):
    results = TestManager(test, {
        'uid': str(student_id),
        'cwd': f'{path}/$uid$/$cwd$',
    }, verbose=False).run()

    return (
        student_id,
        results,
    )


def main(args: argparse.Namespace):
    data = pd.read_csv(args.data)
    repo = Path(args.repo)
    repo.mkdir(exist_ok=True, parents=True)

    out = Path(args.out)
    out.mkdir(exist_ok=True, parents=True)

    with Pool(processes=args.cpu or None) as pool:
        results = pool.map(partial(test, test=args.test, path=repo), data.Id.values)

    columns = ['StudentId']
    data_frame = []
    for (student_id, result), student_name in zip(results, data.Name):
        print(f'Test - {student_id}/{student_name}')
        for test_name, test_result in result.items():
            print(f'\t{test_name}: {test_result}')
        
        if len(columns) == 1:
            columns += result.keys()
        data_frame.append([student_id, *('\n'.join(res) if isinstance(res, list) else res for res in result.values())])

    pd.DataFrame(data_frame, columns=columns).to_csv(f'{str(out.joinpath(Path(args.test).stem))}.csv', index=None)


if __name__ == '__main__':
    parser = argparse.ArgumentParser(
        description='Scripts fetch data from online')
    parser.add_argument('--test', required=True, type=str,
                        help="Test file")

    parser.add_argument('-d', '--data', required=False, default='./data/students.csv', type=str,
                        help="Input data file path")
    parser.add_argument('--repo', required=False, default='./repositories', type=str,
                        help="Directory for repositories")
    parser.add_argument('--out', required=False, default='./results', type=str,
                        help="Result directory path")

    parser.add_argument('--cpu', required=False, default=0, type=int,
                        help="Multiprocessing cpu count")

    main(parser.parse_args())
