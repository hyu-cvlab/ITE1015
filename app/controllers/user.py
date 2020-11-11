from models import User


def by_id(user_id: int)\
        -> User:
    try:
        return User.all[user_id]
    except IndexError as e:
        return {
            "message": str(e),
        }
