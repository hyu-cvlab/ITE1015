from flask import Blueprint, request
from flask.templating import render_template

from controllers import user as User
from controllers import assignment as Assignment

user_view = Blueprint('user', __name__, url_prefix='/')


@user_view.route('/<int:user_id>', methods=['GET'])
def by_id(user_id: int):
    user = User.by_id(user_id)

    return render_template('user.html', user=user.toJSON())


@user_view.route('/<int:user_id>/pull', methods=['GET'])
def pull(user_id: int):
    user = User.by_id(user_id)
    user.fetch()

    return render_template('user.html', user=user.toJSON())


@user_view.route('/<int:user_id>', methods=['PUT'])
def update(user_id: int):
    return User.update(user_id, *map(request.form.get, ['name', 'mail']))
