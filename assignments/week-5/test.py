from typing import Union, Tuple, List, Dict
from enum import Enum


class Sky(Enum):
    CLEAR = 1
    CLOUDY = 2
    OVERCAST = 3
    FOG = 4


class Rain(Enum):
    NONE = 0
    RAIN = 1
    SNOW = 2


DATA = Tuple[Union[Sky, int], Union[Rain, int], int]


class Scoreable:
    def __init__(self):
        self.subset: Dict[str, Scoreable] = {}
    
    def __repr__(self)\
            -> str:
        
        return f'{self.__class__}\n' + '\n'.join((f'\t{key}: {repr(value)}' for key, value in self.subset.items()))
    
    def add(self, key: str, sub: 'Scoreable'):
        self.subset[key] = sub
    
    @property
    def value(self)\
            -> int:
        return 0
    
    def to_score(self)\
            -> int:
        return sum(map(Scoreable.to_score, self.subset.values())) + self.value


class Temperature(Scoreable):
    def __init__(self, temp: int):
        super().__init__()
        self.temp = temp
    
    def __repr__(self)\
            -> str:
        
        return f'Temp: {self.temp}, value: {self.value}'
    
    @property
    def value(self)\
            -> int:
        return 20 - abs(22 - self.temp)
    

class Weather(Scoreable):
    def __init__(self, sky: Sky, rain: Rain):
        super().__init__()
        self.sky = Sky(sky)
        self.rain = Rain(rain)

    def __repr__(self)\
            -> str:
        
        return ', '.join((self.sky.name, self.rain.name)) + f', value: {self.value}'
        
    @property
    def value(self)\
            -> int:
        result = 0
        
        if self.rain == Rain.SNOW:
            result = 14
        elif self.rain == Rain.RAIN:
            result = 5
        elif self.sky == Sky.CLEAR or self.sky == Sky.CLOUDY:
            result = 20
        elif self.sky == Sky.OVERCAST:
            result = 17
        elif self.sky == Sky.FOG:
            result = 10
        else:
            raise NotImplementedError()
        
        return result


class DateManager(Scoreable):
    def __init__(self, data: DATA):
        super().__init__()
        sky, rain, temp = data
        self.add('weather', Weather(sky, rain))
        self.add('temperature', Temperature(temp))

    @property
    def is_bad(self)\
            -> bool:
        
        if (self.subset['weather'].sky == Sky.FOG or self.subset['weather'].rain == Rain.RAIN)\
        or self.subset['temperature'].temp >= 30 or self.subset['temperature'].temp <= 0:
                return True

        return False
        

def solution(data: List[DATA])\
        -> List[int]:
    def prior(tar: int, obj: int, factor: int = 1, priority: List[int] = None)\
            -> bool:
        priority = priority or [0, 1, 3, 2, 5, 6, 4]
        
        if obj == -1:
            return True
        
        return (factor * priority[tar]) > (factor * priority[obj])
    
    datas: List[DateManager] = list(map(DateManager, data))
    
    best_index, worst_index = -1, -1
    best_score, worst_score = 0, 40
    
    for index, data in enumerate(datas):
        score = data.to_score()
        
        if (best_index == -1 or best_score <= score):
            if (best_score == score and prior(index, best_index)) or best_score < score:
                best_index = index
                best_score = score
        
        if data.is_bad and (worst_index == -1 or worst_score >= score):
            if (worst_score == score and prior(index, worst_index, factor=-1)) or worst_score > score:
                worst_index = index
                worst_score = score
    
    return [best_index, worst_index]
