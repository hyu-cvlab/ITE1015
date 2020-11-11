#include <iostream>

template <typename T>
void function(T a) {
    std::cout << a << std::endl;
}

int main() {

    function<double>(97.3);
    
    // 97.3 is casted as 97, because function<int> accept a as int
    function<int>(97.3);
    
    // 97.3 convert to 97 and 97 is 'a' in ASCII code
    function<char>(97.3);

    return 0;
}