#include <iostream>
#include <cassert>
#include "list.h"

int main(int argc, char *argv[]) {
    List<int> *list = new List<int>();
    list->push_back(2);
    list->push_back(3);
    list->push_back(4);
    list->push_back(5);
    list->push_front(1);
    list->push_front(0);

    list->traverse([](const Node<int> &node) {
        std::cout << "Node-value: " << node.value << std::endl;
        std::cout << "Node-next: " << node.next << std::endl;
    });

    delete list;

    return 0;
}
