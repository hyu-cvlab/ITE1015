// set.cc
#include <set>
#include <iostream>

int main() {
    std::set<int> s;

    s.insert(5);
    s.insert(3);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    s.insert(3);

    std::cout << "size: " << s.size() << std::endl;

    // if you using unordered_set, than key is not sorted
    // but default set is sorting key
    for (std::set<int>::iterator it = s.begin(); it != s.end(); it++) {
        std::cout << (*it) << ", ";
    }
    std::cout << std::endl;

    // you can check key exists with find
    // if result of find is end() means there is no key!
    std::set<int>::iterator it = s.find(3);
    if (s.find(3) != s.end()) {
        std::cout << "3 in set" << std::endl;
    }
    if (s.find(8) == s.end()) {
        std::cout << "8 is not in set" << std::endl;
    }

    return 0;
}