from typing import List, Dict, Tuple
from pathlib import Path
from itertools import chain

import pandas as pd

from utils import Utils, repo
from .assignment import Assignment


class User:
    all = {}

    def __init__(self, sid, name):
        self.sid = sid
        self.name = name

        self.score: Dict[str, Dict[str, Tuple[bool, str]]]= {
            assignment.name: assignment.result(self.sid)
            for assignment in Assignment.all.values()
        }

    @property
    def head(self):
        return repo.get_head(self.sid)

    def fetch(self, force: bool = False):
        return repo.fetch(self.sid)

    @staticmethod
    def init(path: Path):
        data = pd.read_csv(str(path))

        for _, (sid, name) in data.iterrows():
            User.all[sid] = User(sid, name)

    def toList(self)\
            -> List[str]:
        return self.toJSON().values()

    def toJSON(self)\
            -> Dict[str, str]:
        return {
            "sid": self.sid,
            "name": self.name,
            "head": self.head,
            "score": self.score,
        }
