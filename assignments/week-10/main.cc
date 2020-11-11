#include <iostream>
#include "canvas.h"

int main() {
    Point p(Point_{3, 1});
    std::cout << p.get_center().first << ", " << p.get_center().second << std::endl;
    std::cout << p.get_visible() << std::endl;
    for (auto v : p.draw()) {
        std::cout << v.first << ", " << v.second << std::endl;
    }
    return 0;
}