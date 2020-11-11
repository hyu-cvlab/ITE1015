#include <iostream>
#include <cassert>

void func_ref(int& a) {
    a += 3;
    std::cout << "The value of a: " << a << std::endl;
}
void func_val(int a) {
    a += 3;
    std::cout << "The value of a: " << a << std::endl;
}
void func_ptr(int* a) {
    *a += 3;
    std::cout << "The value of a: " << *a << std::endl;
}

int main() {
    int a;

    std::cout << "Function val" << std::endl;
    a = 3;
    std::cout << "The value of a: " << a << std::endl;
    func_val(a);
    std::cout << "The value of a: " << a << std::endl;

    std::cout << "Function ref" << std::endl;
    a = 3;
    std::cout << "The value of a: " << a << std::endl;
    func_ref(a);
    std::cout << "The value of a: " << a << std::endl;

    std::cout << "Function ptr" << std::endl;
    a = 3;
    std::cout << "The value of a: " << a << std::endl;
    func_ptr(&a);
    std::cout << "The value of a: " << a << std::endl;

    return 0;
}