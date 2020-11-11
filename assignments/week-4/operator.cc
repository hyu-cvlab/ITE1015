#include <iostream>

int main() {
    int a = 3;
    std::cout << "The value of a: " << a << std::endl;
    std::cout << "The value of a: " << a++ << std::endl;
    std::cout << "The value of a: " << a << std::endl;
    std::cout << "The value of a: " << ++a << std::endl;

    bool cond = (a == 3);
    // conditional operator
    std::cout << "a == 3 is " << (cond ? "True" : "False") << std::endl;

    int x = 3; // 11 (2)
    int y = 2; // 10 (2)

    std::cout << "11 & 10 is " << (x & y) << std::endl; // (10)
    std::cout << "11 | 10 is " << (x | y) << std::endl; // (11)
    std::cout << "11 ^ 10 is " << (x ^ y) << std::endl; // (01)

    bool t = true;
    bool f = false;

    if (t && f) {
        std::cout << "t && f is true" << std::endl;
    }
    if (t || f) {
        std::cout << "t || f is true" << std::endl;
    }

    return 0;
}