#include <iostream>

void function(int* array) {
    array[0] = 34;
    std::cout << "The address of array: " << array << std::endl;
    std::cout << "The value of array[0]: " << *array << std::endl;
}

int main() {
    int size = 5;
    int* array = new int[size];

    std::cout << "The address of array: " << array << std::endl;
    std::cout << "The value of array[0]: " << *array << std::endl;

    function(array);

    std::cout << "The address of array: " << array << std::endl;
    std::cout << "The value of array[0]: " << *array << std::endl;

    delete[] array;

    return 0;
}