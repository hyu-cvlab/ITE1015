// list.cc
#include <iostream>
#include <list>

int main() {
    std::list<int> l;
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);
    l.push_back(6);

    for (auto e : l) {
        std::cout << e << ", ";
    }
    std::cout << std::endl;

    // list also have iterator
    std::list<int>::iterator it = l.begin();

    // but list is not cotingous, so you cannot add iterator like vector
    // std::cout << *(it + 3) << std::endl;

    // you must access items sequentially
    it++;
    std::cout << *it << std::endl;

    return 0;
}
