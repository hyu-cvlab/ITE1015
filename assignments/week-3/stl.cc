#include <iostream>
#include <string>
#include <list>
#include <vector>

int main()
{
    // string is a container which contains characters
    std::string str = "123";

    // list is a container which each node is connected to other
    // The STL container receives as a template parameter what to contain.
    // In this time, we create list contains int type.
    std::list<int> list;

    list.push_back(3);
    list.push_back(2);
    list.push_back(1);
    // now list has 3,2,1

    // you can iter over container using for-each loop
    for (int e : list) {
        std::cout << e << ", ";
    }
    std::cout << std::endl;

    // vector is a container which like a dynamic array
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    // now vectr has 1,2,3

    // Since vectors are like arrays, they can be accessed at random.
    for (int i = 0; i < 3; i++) {
        std::cout << vec[i] << ", ";
    }
    std::cout << std::endl;
}