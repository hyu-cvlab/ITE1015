#include <iostream>
#include <cassert>

template <typename T>
void swap(T* first, T* second) {
    T temp = *first;
    *first = *second;
    *second = temp;
}

int main() {
    int a = 3, b = 2;

    swap(&a, &b);

    assert(a == 2);
    assert(b == 3);
    
    return 0;
}