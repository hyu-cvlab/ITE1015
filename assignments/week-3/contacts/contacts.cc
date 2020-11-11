#include <iostream>

#include "contacts.h"

bool contacts_t::add(student_t student) {
    // TODO:
    // create student with given information and add to students
    // return true if add success else false
    // Students with duplicate IDs must not exist.
    
    int index = -1;
    for (int i = 0; i < m_size; i++) {
        if (students[i].id == student.id) {
            return false;
        } else if (students[i].id == -1 && index == -1) {
            index = i;
        }
    }

    if (index != -1) {
        students[index] = student;
        return true;
    }

    return false;
}

bool contacts_t::add(int id, std::string name) {
    // TODO:
    // create student with given information and add to students
    // add the given student to the first empty space of students.
    // return true if add success else false
    // Students with duplicate IDs must not exist.

    return add((student_t){id, name, " ", " "});
}

bool contacts_t::add(int id, std::string name, std::string phone) {
    // TODO:
    // create student with given information and add to students
    // add the given student to the first empty space of students.
    // return true if add success else false
    // Students with duplicate IDs must not exist.

    return add((student_t){id, name, phone, " "});
}

bool contacts_t::add(int id, std::string name, std::string phone, std::string mail) {
    // TODO:
    // create student with given information and add to students
    // add the given student to the first empty space of students.
    // return true if add success else false
    // Students with duplicate IDs must not exist.

    return add((student_t){id, name, phone, mail});
}

bool contacts_t::remove(int id) {
    // TODO:
    // remove student which match given id
    // return true after remove If can't find a student return false

    for (size_t i = 0; i < m_size; i++) {
        if (students[i].id == id) {
            students[i].id = -1;
            return true;
        }
    }

    return false;
}

bool contacts_t::update(int id, std::string name, std::string phone, std::string mail) {
    // TODO:
    // Finds the student with the given ID and 
    // updates the information to the given values.
    // return true after update else false

    for (int i = 0; i < m_size; i++) {
        if (students[i].id == id) {
            students[i] = {id, name, phone, mail};
            return true;
        }
    }

    return false;
}

student_t contacts_t::find(int id) {
    // TODO:
    // return student which match given id
    // else, return {};
    for (size_t i = 0; i < m_size; i++) {
        if (students[i].id == id) {
            return students[i];
        }
    }

    return {};
}

size_t contacts_t::size() {
    // TODO:
    // return number of students in contacts

    size_t total = 0;
    for (size_t i = 0; i < m_size; i++) {
        if (students[i].id != -1) {
            total += 1;
        }
    }
    return total;
}