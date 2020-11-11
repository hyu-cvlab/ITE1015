#include <iostream>

int main() {
    int num = 30;
    int *ptr = &num;

    std::cout << "The value of num: " << num << std::endl;
    std::cout << "The address of num: " << &num << std::endl;
    std::cout << "The value of ptr: " << ptr << std::endl;
    std::cout << "The address of ptr: " << &ptr << std::endl;
    std::cout << "The value of (pointer ptr): " << *ptr << std::endl;

    const int* const_ptr = &num;
    int* const ptr_const = &num;

    std::cout << "The pointer value of const_ptr: " << *const_ptr << std::endl;
    std::cout << "The value of const_ptr: " << const_ptr << std::endl;

    std::cout << "The pointer value of ptr_const: " << *ptr_const << std::endl;
    std::cout << "The value of ptr_const: " << ptr_const << std::endl;

    // Below lines raise error
    // *const_ptr = 15;
    // ptr_const = &const_ptr;

    return 0;
}