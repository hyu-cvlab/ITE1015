#ifndef __USER_H__
#define __USER_H__

#include <string>
#include "college.h"


class User {
public:
    User(const std::string& name, size_t id, College& college)
    : name(name), id(id), college(college) {
    }
    virtual ~User() {}

    std::string getName() const {
        return name;
    }

    size_t getId() const {
        return id;
    }

    College& getCollege() const {
        return college;
    }

private:
    std::string name;
    size_t id;
    College& college;
};

class Student : public User {
public:
    Student(const std::string& name, size_t id, College& college)
    : User(name, id, college) {
    }

};

class Employee : public User {
public:
    Employee(const std::string& name, size_t id, College& college)
    : User(name, id, college) {
    }
};

class Professor : public User {
public:
    Professor(const std::string& name, size_t id, College& college)
    : User(name, id, college) {
    }
};

#endif
