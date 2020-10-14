#include <iostream>
#include <cassert>
#include "list.h"

int main(int argc, char *argv[]) {
    List *list = new List();
    list->push_back(2);
    list->push_back(3);
    list->push_back(4);
    list->push_back(5);
    list->push_front(1);
    list->push_front(0);

    assert(list->pop_back() == 5);
    assert(list->pop_front() == 0);
    assert(list->pop_front() == 1);
    assert(list->pop_front() == 2);
    assert(list->pop_front() == 3);
    assert(list->pop_front() == 4);

    assert(list->pop_front() == 0);
    
    list->traverse([](const Node &node) {
        std::cout << "Node-value: " << node.value << std::endl;
        std::cout << "Node-next: " << node.next << std::endl;
    });

    delete list;

    return 0;
}
