#include <iostream>
#include <string>
#include <vector>

class Person {
public:
    int age;
    std::string name;

    Person(int age, std::string name)
    : age(age), name(name) {
        
    }
    
    void hello() {
        std::cout << "Hello, my name is " << this->name << std::endl;
    }
};

class Student
: public Person {
public:
    int student_id;
    std::string university;

    Student(int age, std::string name, int student_id, std::string university)
    : Person(age, name), student_id(student_id), university(university) {
    }
    
    // overriding
    void hello() {
        std::cout << "Hello, my name is " << this->name << std::endl;
        std::cout << "My id is " << this->student_id << std::endl;
    }
};

class Professor
: public Person {
public:
    std::string office;

    Professor(int age, std::string name, std::string office)
    : Person(age, name), office(office) {
        
    }
    
    // overriding
    void hello() {
        std::cout << "Hello, my name is " << this->name << std::endl;
        std::cout << "My office is " << this->office << std::endl;
    }
};

int main() {
    std::vector<Person> people;
    std::vector<Student> students;
    std::vector<Professor> professors;

    Student jiun{25, "jiun", 2019170229, "hyu"};
    Student jisu{24, "jisu", 2015170229, "cnu"};
    Student soomin{23, "soomin", 201417024, "hyu"};

    students.push_back(jiun);
    students.push_back(jisu);
    students.push_back(soomin);
    // we can handle Student as Person (because Student inherits Person)
    // But in this case, instance is considered like Person.
    people.push_back(jiun);
    people.push_back(jisu);
    people.push_back(soomin);

    Professor jongwoo{45, "jongwoo", "itbt505"};
    professors.push_back(jongwoo);
    people.push_back(jongwoo);

    for (auto person : people) {
        person.hello();
    }

    for (auto student : students) {
        student.hello();
    }

    for (auto professor : professors) {
        professor.hello();
    }
}
