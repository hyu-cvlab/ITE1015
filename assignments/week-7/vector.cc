// vector.cc
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v;

    // size is vector size, capacity is allocated memory space
    // Vectors allocate a larger amount of memory for efficiency.
    // This prevents reassignment every time the size increases.
    // Note that reallocating memory is expensive.
    std::cout << "size: " << v.size() << std::endl;
    std::cout << "capacity: " << v.capacity() << std::endl;

    for (int i = 0; i < 5; i++) {
        v.push_back(i);
        std::cout << "size: " << v.size() << std::endl;
        std::cout << "capacity: " << v.capacity() << std::endl;
    }
    // so, the size is 5, but capa is 8
    // Yes, Basically, capacity is allocated as much as a power of 2.

    // resize 7 < capacity 8
    // So, reallocation no required
    v.resize(7);
    std::cout << "size: " << v.size() << std::endl;
    std::cout << "capacity: " << v.capacity() << std::endl;

    // Executing pop back does not reduce capacity.
    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.pop_back();
    std::cout << "size: " << v.size() << std::endl;
    std::cout << "capacity: " << v.capacity() << std::endl;

    for (auto e : v) {
        std::cout << e << ", ";
    }
    std::cout << std::endl;

    return 0;
}
