from models import Assignment


def by_name(name: str)\
        -> Assignment:
    try:
        return Assignment.all[name]
    except IndexError as e:
        return {
            "message": str(e),
        }
