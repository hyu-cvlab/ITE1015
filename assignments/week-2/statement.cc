// file: statement.cc
#include <iostream>

int main() {
    if (true) {
        std::cout << "This statement is always executed." << std::endl;
    } else {
        std::cout << "This statement is never executed." << std::endl;
    }
    
    // Most programming languages assume nonzero numbers are true.
    if (0) {
        // so, this statement will never be executed
        std::cout << "0 is same as false" << std::endl;
    }
    
    if (1) {
        std::cout << "1 is same as true" << std::endl;
    } else if (2) {
        // This is true because 2 is also a non-zero number.
        // However, in the else if statement, 
        // if the condition that is true from the top condition is met first, 
        // the statement after it is not executed.
        std::cout << "2 is same as true" << std::endl;
    }

    if ("some string") {
        std::cout << "string is true! too" << std::endl;
    }
    
    if (true) {
        if (true) {
            if (true) {
                std::cout << "nested statement" << std::endl;
            }
        }
    }
    
    return 0;
}