#include <iostream>
#include <cassert>

#include "../contacts.h"

int main() {
    int size = 4;
    auto contacts = contacts_t(size);

    assert(contacts.size() == 0);
    contacts.add({0, "name", "phone", "mail"});
    assert(contacts.size() == 1);
    contacts.add({1, "name", "phone", "mail"});
    assert(contacts.size() == 2);
    contacts.add({2, "name", "phone", "mail"});
    assert(contacts.size() == 3);
    contacts.add({3, "name", "phone", "mail"});
    assert(contacts.size() == 4);
    contacts.remove(3);
    assert(contacts.size() == 3);

    return 0;
}
