#include <iostream>
#include <cassert>

#include "../contacts.h"

int main() {
    int size = 4;
    auto contacts = contacts_t(size);

    // check add
    assert(contacts.add({0, "name", "phone", "mail"}));
    assert(contacts.add({1, "name", "phone", "mail"}));
    assert(contacts.add({2, "name", "phone", "mail"}));
    assert(contacts.add({3, "name", "phone", "mail"}));

    // check exceed
    assert(!contacts.add({4, "name", "phone", "mail"}));

    // check duplicated
    assert(!contacts.add({3, "name", "phone", "mail"}));

    contacts = contacts_t(size);

    // check overloading
    assert(contacts.add(0, "name", "phone", "mail"));
    assert(contacts.add(1, "name", "phone"));
    assert(contacts.add(2, "name"));

    return 0;
}
