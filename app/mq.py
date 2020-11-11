import json

from celery import Celery

from utils.repo import get_head, fetch
from utils.test import test


class Queue:
    i = None

    @staticmethod
    def init(host: str, port: int = 6379):
        
        BROKER_URL = f'redis://{host}:{port}/0'
        CELERY_RESULT_BACKEND = f'redis://{host}:{port}/0'

        Queue.i = Celery('tasks', broker=BROKER_URL, backend=CELERY_RESULT_BACKEND)
        Queue.all = {
            f.__name__: f 
            for f in list(map(Queue.i.task, [
                fetch,
                test,
            ]))
        }


# if __name__ == "__main__":
with open('config.json') as f:
    config = json.load(f)
Queue.init(config['app']['mq']['host'], config['app']['mq']['port'])
app = Queue.i
