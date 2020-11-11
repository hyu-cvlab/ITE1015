#include <iostream>

int main() {
    char str1[] = "String";
    char str2[32] = "String";
    char str3[] = {'S', 't', 'r', 'i', 'n', 'g', '\0'};

    std::cout << str1 << std::endl;
    std::cout << str2 << std::endl;
    std::cout << str3 << std::endl;

    char str4[] = "String";
    str4[3] = '\0';
    std::cout << str4 << std::endl; // will print only "Str"
    std::cout << &(str4[4]) << std::endl; // will print remain parts "ng"
    std::cout << (str4+4) << std::endl; // it's same as above

    std::string str5 = "String";
    std::cout << str5 << std::endl;
    std::cout << "length of str5: " << str5.size() << std::endl; // std::string has many features.
    std::cout << str5.c_str() << std::endl; // return char pointer for Backward Compatibility
}