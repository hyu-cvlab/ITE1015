#include <iostream>
#include <cassert>

template <typename T>
T* realloc(T* pointer, size_t org_size, size_t new_size) {
    // TODO
    // return new allocated memory

    T* new_array = new T[new_size];

    for (int i = 0; i < org_size; i++) {
        new_array[i] = pointer[i];
    }

    return new_array;
}

int main() {
    int* array = new int[32];

    for (int i = 0; i < 32; i++) {
        array[i] = i;
    }

    array = realloc(array, 32, 64);

    // data guarantee
    for (int i = 0; i < 32; i++) {
        assert(array[i] == i);
    }
    // also you can assign re-allocated area
    for (int i = 0; i < 32; i++) {
        array[32+i] = i;
    }
    

    return 0;
}