from typing import List, Dict
from functools import cached_property
from pathlib import Path
import json

from utils import Utils
from utils.test import test


class Assignment:
    all = {}

    def __init__(self, path: Path):
        self.path = path
        self.name = path.stem

    @staticmethod
    def init(path: Path):
        assignments = path.glob('*.json')
        for assignment in assignments:
            Assignment.all[assignment.stem] = Assignment(assignment)

    def submit(self, sid: int):
        def post_process(string: str):
            string = string.replace('/home/jiun', '')
            string = string.replace('ite1015', '')
            string = string[:64]
            return string

        _, res = test(sid, self.path)
        cache = Path(Utils.config['path']).joinpath('cache', str(sid))
        cache.mkdir(exist_ok=True, parents=True)

        result = {test_name: (
            all(results[0]),
            '\n'.join(map(post_process, map(str.strip, results[1]))).strip()
        ) for test_name, results in res.items()}
    
        with open(str(cache.joinpath(self.path.name)), 'w') as f:
            json.dump(result, f)

        return result

    def result(self, sid: int):
        cache = Path(Utils.config['path']).joinpath('cache', str(sid), self.path.name)
        
        if cache.is_file():
            with open(str(cache)) as f:
                res = json.load(f)
        else:
            res = self.submit(sid)
        
        return res

    def toList(self)\
            -> List[str]:
        return self.toJSON().values()

    def toJSON(self)\
            -> Dict[str, str]:
        return {
            "name": self.name,
        }
