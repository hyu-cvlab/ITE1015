// file: the-starry-night.cc
#include <iostream>

int main() {
    int N;
    std::cin >> N;
    
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < i; j++)
        {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    
    return 0;
}