#include <string>
#include <functional>

#include "node.h"

template <typename T>
class List {
public:
    List() : count(0) {
        head = new Node<T>(0, nullptr);
    }
    ~List() {
        // TODO: write your code here
        // release remain nodes before delete head node
        delete head;
    }

    void push_front(T value) {
        // TODO: write your code here
        // create new node with value
        // and add node to front of list
    }
    void push_back(T value) {
        // TODO: write your code here
        // create new node with value
        // and add node to back of list
    }
    T pop_front() {
        // TODO: write your code here
        // remove front node(not head)
        // and return its value
        // if try to remove head node return 0
    }
    T pop_back() {
        // TODO: write your code here
        // remove back node(not head)
        // and return its value
        // if try to remove head node return 0
    }

    size_t size() {
        // TODO: write your code here
        // return current items in list (except head)
    }

    void traverse(const std::function<void(const Node<T>&)>& f) {
        for (Node<T>* node = head->next; node != nullptr; node = node->next) {
            f(*node);
        }
    }

private:
    Node<T>* head;
    size_t count;
    
    // OPTIONAL: you can write helper functions
};
