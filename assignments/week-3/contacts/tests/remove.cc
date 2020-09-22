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

    assert(!contacts.remove(34));
    assert(contacts.remove(0));
    assert(!contacts.remove(0));
    assert(contacts.remove(1));
    assert(contacts.remove(2));
    assert(contacts.remove(3));

    return 0;
}
