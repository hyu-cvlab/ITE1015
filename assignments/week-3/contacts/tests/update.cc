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

    assert(contacts.update(0, "name2", "1", "2"));
    assert(!contacts.update(4, "2", "3", "4"));

    for (int i = 0; i < size; i++) {
        if (contacts.students[i].id == 0) {
            assert(contacts.students[i].name == "name2");
            assert(contacts.students[i].phone == "1");
            assert(contacts.students[i].mail == "2");
            break;
        }
    }

    return 0;
}
