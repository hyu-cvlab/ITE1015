template <typename T>
class Node {
public:
    Node() {}
    Node(T value) : value(value) {}
    Node(T value, Node* next) : value(value), next(next) {}
    
    T value;
    Node* next;
};
