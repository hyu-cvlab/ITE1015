#include <iostream>

void function(int a) {
    std::cout << "function with int a called!" << std::endl;
}
void function(int a, int b) {
    std::cout << "function with int a, int b called!" << std::endl;
}
void function(double a) {
    std::cout << "function with double a called!" << std::endl;
}

int main() {
    function(3);
    function(4, 5);
    function(2.0);
    return 0;
}