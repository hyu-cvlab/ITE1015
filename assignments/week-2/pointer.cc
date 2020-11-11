// file: pointer.cc
#include <iostream>

int main() {
    int var = 129;
    // int* is type for pointer of int
    // So, A* is type for pointer of A
    int* var_address = &var;
    int vluae_of_var_address = *var_address;

    std::cout << "Value of var: " << var << std::endl;
    std::cout << "Address of var: " << var_address << std::endl;
    std::cout << "Value of Address of var: "
              << vluae_of_var_address << std::endl;

    // pointer is just number of address
    int ary[3];
    ary[0] = 6;
    ary[1] = 23;
    ary[2] = 42;

    int *address_of_ary_0 = &ary[0];
    int *address_of_ary_1 = &ary[1];
    int *address_of_ary_2 = &ary[2];

    std::cout << "Address of ary[0]: " << address_of_ary_0 << std::endl;
    std::cout << "Address of ary[1]: " << address_of_ary_1 << std::endl;
    std::cout << "Address of ary[2]: " << address_of_ary_2 << std::endl;

    std::cout << "Address of ary[2] - ary[0]: " 
              << address_of_ary_2 - address_of_ary_0 << std::endl;
    std::cout << "Address of ary[1] - ary[0]: "
              << address_of_ary_1 - address_of_ary_0 << std::endl;

    std::cout << "The value of (address of ary[0]): "
              << *address_of_ary_0 << std::endl;
    std::cout << "The value of (address of ary[0] + 1): "
              << *(address_of_ary_0+1) << std::endl;
    std::cout << "The value of (address of ary[0] + 2): "
              << *(address_of_ary_0+2) << std::endl;

    return 0;
}