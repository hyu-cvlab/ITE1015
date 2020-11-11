// iterator.cc
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v(5);

    v[0] = 1;
    v[1] = 2;
    v[2] = 3;
    v[3] = 4;
    v[4] = 5;
    // end is next of last element 
    // v[5] not exists, 

    for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        std::cout << *it << ", ";
    }
    std::cout << std::endl;

    std::vector<int>::iterator it = v.begin();

    std::cout << *it << std::endl;          // the value of v[0]
    std::cout << *(it + 3) << std::endl;    // the value of v[3]

    // insert 10 before v[3], so new v[3] will be 10
    v.insert(v.begin() + 3, 10);
    for (auto e : v) {
        std::cout << e << ", ";
    }
    std::cout << std::endl;

    // remove v[4] the value is 4.
    v.erase(v.begin() + 4);
    for (auto e : v) {
        std::cout << e << ", ";
    }
    std::cout << std::endl;

    // iterator loop
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        std::cout << *it << ", ";
    }
    std::cout << std::endl;

    // reverse iterator
    for (std::vector<int>::reverse_iterator it = v.rbegin();
         it != v.rend(); it++) {
        std::cout << *it << ", ";
    }
    std::cout << std::endl;

    return 0;
}
