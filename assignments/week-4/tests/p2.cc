#include <iostream>
#include <cassert>
#include <string>

#include "../problem2.h"

int main() {
    dynamic_array<std::string> da(10);

    for (int i = 0; i< 5; i++) {
        da.push_front(std::to_string(i));
    }

    for (int i = 5; i < 10; i++) {
        da.push_back(std::to_string(i));
    }
    
    for (int i = 0; i < 5; i ++) {
        auto a1 = da.pop_front();
        auto a2 = da.pop_back();

        assert(a1 == std::to_string(4 - i));
        assert(a2 == std::to_string(9 - i));
    }

    return 0;
}
