#include <iostream>
#include <cassert>

#include "../problem1.h"

int main() {
    initialize(10);
    for (int i = 0; i < 10; i++) {
        push_back(i);
    }

    for (int i = 9; i >=0; i--) {
        assert(pop_back() == i);
    }

    release();

    return 0;
}
