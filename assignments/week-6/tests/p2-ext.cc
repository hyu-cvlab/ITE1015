#include <iostream>
#include <vector>
#include <cassert>
#include <string>

#include "double_linked_list.h"

int main() {
    auto list = new List<std::string>();

    for (int i = 0; i < 10; i++) {
        list->push_front(std::to_string(i));
    }

    for (int i = 0; i < 10; i++) {
        list->push_back(std::to_string(i + 10));
    }

    // 9 8 7 6 5 4 3 2 1 0 10 11 12 13 14 15 16 17 18 19 
    assert(list->size() == 20);

    std::vector<int> k{ 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 };
    std::vector<std::string> v;
    std::vector<Node<std::string>> nodes;
    std::vector<Node<std::string>*> node_ptr;
    list->traverse([&v, &nodes, &node_ptr](const Node<std::string>& node) {
        v.push_back(node.value);
        nodes.push_back(node);
        node_ptr.push_back(node.next);
    });

    assert(v.size() == 20);
    assert(nodes.size() == 20);
    assert(node_ptr.size() == 20);

    for (int i = 0; i < 19; i++) {
        assert(nodes[i].next == node_ptr[i]);
        assert(nodes[i+1].prev == node_ptr[i]);
    }

    for (int i = 0; i < 20; i++) {
        assert(std::to_string(k[i]) == v[i]);
    }

    for (int i = 0; i < 10; i++) {
        assert(std::to_string(19 - i) == list->pop_back());
    }

    for (int i = 0; i < 10; i++) {
        assert(std::to_string(9 - i) == list->pop_front());
    }

    return 0;
}
