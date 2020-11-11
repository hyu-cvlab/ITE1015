// map.cc
#include <map>
#include <iostream>

int main() {
    // map require two template variable <key, value>
    std::map<int, int> m;

    // insert require pair of <key, value>
    // see also std::pair
    m.insert({3, 9});
    m.insert({2, 4});
    m.insert({1, 1});
    m.insert({2, 14});

    std::cout << "size: " << m.size() << std::endl;

    // if you using unordered_map, than key is not sorted
    // but default map is sorting key
    for (std::map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
        // In pair, we can access first element of pair(in this time, key)
        // using .first member.
        // .second is value
        std::cout << it->first << ": " << it->second << std::endl;
    }

    // you can check key exists with find
    // if result of find is end() means there is no key!
    if (m.find(3) != m.end()) {
        std::cout << "3 in map" << std::endl;
    }
    if (m.find(8) == m.end()) {
        std::cout << "8 is not in map" << std::endl;
    }

    return 0;
}