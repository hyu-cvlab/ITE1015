// file: iteration.cc
#include <iostream>

int main() {
    // this is while loop
    int n = 0;
    while (n < 10) {
        std::cout << n << ", ";
        n = n + 1;
    }
    std::cout << std::endl;
    // expect, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 
    
    // this is do-while loop
    int m = 0;
    do {
        std::cout << m << ", ";
        m = m + 1;
    } while (m < 10);
    std::cout << std::endl;
    // expect, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 

    // this is for loop
    //  (init     ; cond  ; inc)
    for (int i = 0; i < 10; i++) {
        std::cout << i << ", ";
    }
    std::cout << std::endl;
    // expect, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 
    
    return 0;
}