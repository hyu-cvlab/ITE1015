#include <iostream>
#include <string>
#include "shape.h"

int main() {
    size_t x, y, w, h, id;
    std::string command, temp;

    std::cin >> w >> h;
    Canvas canvas{h, w};


    for (std::cin >> command; command != "exit"; std::cin >> command) {

        if (command == "add") {
            std::cin >> temp;
            if (temp == "point") {
                std::cin >> x >> y;
                std::cout << canvas.add(new Point{{x, y}}) << std::endl;
            } else if (temp == "rectangle") {
                std::cin >> x >> y >> w >> h;
                std::cout << canvas.add(new Rectangle{{x, y}, {w, h}}) << std::endl;
            } else if (temp == "circle") {
                std::cin >> x >> y >> w ;
                std::cout << canvas.add(new Circle{{x, y}, w}) << std::endl;
            } else if (temp == "triangle") {
                std::cin >> x >> y >> w >> h;
                std::cout << canvas.add(new Triangle{{x, y}, {w, h}}) << std::endl;
            }
        } else if (command == "set") {
            std::cin >> id;
            std::cin >> command;
            if (command == "fill") {
                std::cin >> command;
                canvas.at_fillable(id)->set_fill(command == "true");
            } else if (command == "visible") {
                std::cin >> command;
                canvas.at_drawable(id)->set_visible(command == "true");
            } else if (command == "size") {
                std::cin >> w >> h;
                canvas.at_fillable(id)->set_size({w, h});
            } else if (command == "offset") {
                std::cin >> x >> y;
                canvas.at_drawable(id)->set_offset({x, y});
            }
        } else if (command == "draw") {
            canvas.draw();
        } else if (command == "clear") {
            canvas.clear();
        }
    }

    return 0;
}