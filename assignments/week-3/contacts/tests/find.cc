#include <iostream>
#include <cassert>

#include "../contacts.h"

int main() {
    int size = 4;
    auto contacts = contacts_t(size);

    contacts.add({0, "name", "phone", "mail"});
    contacts.add({1, "name", "phone", "mail"});
    contacts.add({2, "name", "phone", "mail"});
    contacts.add({3, "name", "phone", "mail"});

    {
        auto student = contacts.find(0);
        assert(student.id == 0);
        assert(student.name == "name");
        assert(student.phone == "phone");
        assert(student.mail == "mail");
    }
    {
        auto student = contacts.find(1);
        assert(student.id == 1);
        assert(student.name == "name");
        assert(student.phone == "phone");
        assert(student.mail == "mail");
    }
    {
        auto student = contacts.find(2);
        assert(student.id == 2);
        assert(student.name == "name");
        assert(student.phone == "phone");
        assert(student.mail == "mail");
    }
    {
        auto student = contacts.find(3);
        assert(student.id == 3);
        assert(student.name == "name");
        assert(student.phone == "phone");
        assert(student.mail == "mail");
    }
    {
        auto student = contacts.find(4);
        assert(student.id == 0);
        assert(student.name == "");
        assert(student.phone == "");
        assert(student.mail == "");
    }

    return 0;
}
