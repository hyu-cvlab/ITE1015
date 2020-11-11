// file: io.cc
#include <iostream>

int main() {
    // print "Hello World!" through output stream (std::cout).
    // The std::endl manipulator can be used to break lines ('\n').
    std::cout << "Hello World!" << std::endl;

    // cout can print integer, string and other various types.
    std::cout << 3 << ", " << 2 << std::endl;

    // x is int type variable
    // Unlike Python, you need to declare a type of variable
    // Also cout can print value of variable
    int x = 3;
    std::cout << x << std::endl;

    // You can use `cin` to store the input value in a variable
    std::cin >> x;

    // And just printout inputed value that store in variable x
    std::cout << x << std::endl;

    // std::string is string type contains some characters.
    std::string str;

    // save inputed string to variable str
    std::cin >> str;

    std::cout << str << std::endl;

    return 0;
}