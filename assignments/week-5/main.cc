// main.cc
#include <iostream>
#include "point.h"
#include "utility.h"

inline void move(Point& pt, int x, int y) {
    pt.x += x;
    pt.y += y;
}

int main() {
    Point p1{0, 0};
    Point p2{3, 5};
    
    std::cout << "Distance: " << distance(p1, p2) << std::endl;
    
    move(p1, 0, 3);
    move(p2, -3, -2);
    
    std::cout << "Distance: " << distance(p1, p2) << std::endl;
    
    return 0;
}
