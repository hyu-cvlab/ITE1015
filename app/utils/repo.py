from pathlib import Path
import subprocess

from utils import Utils


def get_head(student_id: int)\
        -> str:
    path = Path(Utils.config['path']).joinpath('repositories', str(student_id))

    result = 0
    try:
        result = subprocess.check_output(['git', 'rev-parse', 'HEAD'],
                                cwd=str(path),
                                stderr=subprocess.STDOUT).decode('utf-8')[:8]
    except subprocess.CalledProcessError as e:
        print("Exception on process, rc=", e.returncode, "output=", e.output)

    return result


def fetch(student_id: int) \
        -> dict:
    path = Path(Utils.config['path']).joinpath('repositories')
    login = f"{Utils.config['key']['a']}:{Utils.config['key']['b']}"

    print(f'Processing {student_id} ...')
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
            process = subprocess.Popen(['git', 'pull', 'origin', 'master'], cwd=str(path.joinpath(str(student_id))), stdout=subprocess.PIPE, stderr=subprocess.PIPE)

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
