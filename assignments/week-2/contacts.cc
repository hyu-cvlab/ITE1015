// file: contacts.cc
#include <iostream>

struct student_t {
    int id;
    std::string name;
    std::string phone;
};

int main() {
    int N, M, query;
    bool flag = false;
    student_t students[101];
    
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> students[i].id;
        std::cin >> students[i].name;
        std::cin >> students[i].phone;
    }
    
    std::cin >> M;
    for (int i = 0; i < M; i++) {
        flag = false;
        std::cin >> query;
        for (int j = 0; j < N; j++) {
            if (students[j].id == query) {
                std::cout << students[j].name << "," << students[j].phone << std::endl;
                flag = true;
                break;
            }
        }
        if (!flag) {
            std::cout << "Unknown" << std::endl;
        }
    }

    return 0;
}