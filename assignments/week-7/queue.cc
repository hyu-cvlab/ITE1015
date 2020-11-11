// queue.cc
#include <queue>
#include <iostream>

int main() {
    std::queue<int> queue;

    queue.push(10);
    queue.push(20);
    queue.push(30);

    std::cout << queue.front() << std::endl;
    queue.pop();
    std::cout << queue.front() << std::endl;
    queue.pop();
    std::cout << queue.front() << std::endl;
    queue.pop();

    return 0;
}