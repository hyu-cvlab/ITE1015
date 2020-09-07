import argparse
from pathlib import Path
from functools import partial
from collections import Counter
from multiprocessing import Pool
import subprocess
import pandas as pd 


def fetch(student_id, login: str = None, path: Path = None):
    command = f'git clone https://{login}@hconnect.hanyang.ac.kr/2020_ite1015_12522/{student_id}.git {str(path.joinpath(str(student_id)))}'
    process = subprocess.Popen(command.split(' '), stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    status = 'ok'

    try:
        outs, errs = process.communicate(timeout=30)
        outs, errs = outs.decode('utf-8'), errs.decode('utf-8')

    except Exception as e:
        process.kill()
        print(f'While processing {student_id}, occur {e}')

        outs, errs = '', 'Failed'

    if not outs and errs:
        if 'already exists' in errs:
            status = 'exists'
            process = subprocess.Popen(['git', 'pull'], cwd=str(path.joinpath(str(student_id))), stdout=subprocess.PIPE, stderr=subprocess.PIPE)

            try:
                outs, errs = process.communicate(timeout=30)
                outs, errs = outs.decode('utf-8'), errs.decode('utf-8')
            
            except Exception as e:
                process.kill()
                print(f'While processing {student_id}, occur {e}')

            if 'Already up to date.' in outs:
                status = 'up to date'
            elif 'but no such ref was fetched' in errs:
                status = 'empty'
            else:
                status = 'pulled'

        elif 'not found' in errs:
            status = 'not-found'

    return {
        'status': status,
        'message': outs or errs,
    }

def main(args: argparse.Namespace):
    data = pd.read_csv(args.data)
    repo = Path(args.repo)
    repo.mkdir(exist_ok=True, parents=True)

    login = f'{args.id}:{args.pw}'
    with Pool(processes=args.cpu or None) as pool:
        results = pool.map(partial(fetch, login=login, path=repo), data.Id.values)
        
    counter = Counter([result['status'] for result in results])
    print(counter)


if __name__ == '__main__':
    parser = argparse.ArgumentParser(
        description='Scripts fetch data from online')
    parser.add_argument('--id', required=True,
                        help="Id of hconnect gitlab")
    parser.add_argument('--pw', required=True,
                        help="Pw of hconnect gitlab")

    parser.add_argument('-d', '--data', required=False, default='./data/students.csv', type=str,
                        help="Input data file path")
    parser.add_argument('--repo', required=False, default='./repositories', type=str,
                        help="Directory for repositories")

    parser.add_argument('--cpu', required=False, default=0, type=int,
                        help="Multiprocessing cpu count")

    main(parser.parse_args())
