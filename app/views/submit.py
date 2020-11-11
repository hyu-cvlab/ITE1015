from flask import Blueprint
from flask.helpers import url_for
from werkzeug.utils import redirect

from models import Assignment, User

submit_view = Blueprint('submit', __name__, url_prefix='/')


@submit_view.route('/<string:assignment_id>/<int:user_id>', methods=['GET'])
def submit(assignment_id: str, user_id: int):
    User.all[user_id].score[assignment_id] = Assignment.all.get(assignment_id).submit(user_id)
    return redirect(url_for('user.by_id', user_id=user_id))
