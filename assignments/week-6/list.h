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
        push(value, head);
    }
    void push_back(T value) {
        // TODO: write your code here
        // create new node with value
        // and add node to back of list
        push(value, find_last());
    }
    T pop_front() {
        // TODO: write your code here
        // remove front node(not head)
        // and return its value
        // if try to remove head node return 0
        return pop(head->next);
    }
    T pop_back() {
        // TODO: write your code here
        // remove back node(not head)
        // and return its value
        // if try to remove head node return 0
        return pop(find_last());
    }

    size_t size() {
        // TODO: write your code here
        // return current items in list (except head)
        return count;
    }

    void traverse(const std::function<void(const Node<T>&)>& f) {
        for (Node<T>* node = head->next; node != nullptr; node = node->next) {
            f(*node);
        }
    }

private:
    Node<T>* head;
    size_t count;

    void push(T value, Node<T>* node) {
        Node<T> *next = node->next;
        node->next = new Node<T>(value, next);
        count += 1;
    }
    T pop(Node<T>* node) {
        if (node == head || node == nullptr) {
            return 0;
        }

        T value = node->value;
        Node<T>* prev = find_prev_node(node);
        prev->next = node->next;
        delete node;
        count -= 1;
        return value;
    }

    Node<T>* find_node(T value) {
        Node<T>* prev = find_prev(value);

        if (prev != nullptr) {
            return find_prev(value)->next;
        }
        return nullptr;
    }
    Node<T>* find_prev(T value) {
        Node<T>* prev = head;
        while (prev->next != nullptr) {
            if (prev->next->value == value) {
                return prev;
            }
            prev = prev->next;
        }
        return nullptr;
    }
    Node<T>* find_prev_node(Node<T>* node) {
        Node<T>* prev = head;
        while (prev->next != nullptr) {
            if (prev->next == node) {
                return prev;
            }
            prev = prev->next;
        }
        return nullptr;
    }
    Node<T>* find_last() {
        Node<T>* node = head;
        while (node->next != nullptr) {
            node = node->next;
        }
        return node;
    }
};
