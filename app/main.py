from pathlib import Path
import ssl
import json

from flask import Flask
from flask.templating import render_template

from utils import Utils
from models import User, Assignment
from views import __all__ as views


def main(app: Flask):
    config = Path('config.json')
    if not config.is_file():
        raise RuntimeError("config file required")

    with open(str(config)) as f:
        config = json.load(f)

    Utils.config = config
    Assignment.init(Path(config['path']).joinpath('scripts', 'tests'))
    User.init(Path(config['path']).joinpath('data', 'students.csv'))

    ssl_context = ssl.SSLContext(ssl.PROTOCOL_TLS)
    ssl_context.load_cert_chain(certfile=config['app']['cert']['certfile'],
                                keyfile=config['app']['cert']['keyfile'])

    any(map(app.register_blueprint, views))
    @app.route('/', methods=['GET'])
    def index():
        users = list(map(User.toJSON, User.all.values()))
        for user in users:
            user['assigns'] = [all(result[0] for result in results.values()) for results in user['score'].values()]
            
        return render_template('index.html', 
                               users=users,
                               assignments=Assignment.all.keys())

    app.run(debug=False,
            host=config['app']['host'],
            port=config['app']['port'],
            threaded=True,
            ssl_context=ssl_context)


if __name__ == "__main__":
    main(Flask(__name__))
