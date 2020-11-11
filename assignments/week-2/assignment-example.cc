// file: assignment-example.cc
#include <iostream>

int main() {
    int N;
    std::cin >> N;
    
    for (int i = 1; i < 10; i++) {
        std::cout << i << "x" << N << "=" << i * N << std::endl;
    }
    return 0;
}