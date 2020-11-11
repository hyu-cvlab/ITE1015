// file: structure.cc
#include <iostream>

// Conventionally, _t is appended to indicate that it is a type.
struct student_t {
    int id;
    std::string name;
} student_a, student_b;

int main() {
    student_a.id = 2019170229;
    student_a.name = "jiun";

    student_b.id = 1;
    student_b.name = "b";

    std::cout << "Student A, id: " << student_a.id << std::endl;
    std::cout << "Student A, name: " << student_a.name << std::endl;

    std::cout << "Student B, id: " << student_b.id << std::endl;
    std::cout << "Student B, name: " << student_b.name << std::endl;

    return 0;
}