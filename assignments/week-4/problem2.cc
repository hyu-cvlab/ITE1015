#include <iostream>

template <typename T>
struct dynamic_array {
    T* pointer = nullptr;
    size_t cap = 0;

public:
    dynamic_array(size_t cap)
    : cap(cap) {
        this->pointer = new T[cap];
    }

    void push_front(const T& element) {
        // TODO: push_front
        // if array is [2,3] and pop_front(1) called
        // then array should be [1,2,3]
    }

    void push_back(const T& element) {
        // TODO: push_back
        // if array is [1,2] and pop_front(3) called
        // then array should be [1,2,3]
    }

    T pop_front() {
        // TODO: pop front
        // if array is [1,2,3], and pop_front called
        // then array should be [2,3] and return 1
    }

    T pop_back() {
        // TODO: pop back
        // if array is [1,2,3], and pop_front called
        // then array should be [1,2] and return 3
    }

    ~dynamic_array() {
        delete[] this->pointer;
    }
};

int main() {

    {
        auto v = dynamic_array<int>(32);
    }

    return 0;
}