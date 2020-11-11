#include <iostream>

int* array;
size_t cap = 0;

void initialize(int cap_) {
    array = new int[cap_];
    cap = cap_;
}

void release() {
    delete[] array;
}

void push_back(int element) {
    // TODO:
    // insert element to back of array
    // if array is [1,2,3], and push_back(4) called,
    // then array should be [1,2,3,4]
}

int pop_back() {
    // TODO:
    // return last element of array and remove it from array
    // if array is [1,2,3,4] and pop_back() called,
    // then array should be [1,2,3] and pop_back() return 4.
}

int len() {
    // TODO:
    // return size of array
}

int main() {
    return 0;
}