#include "student.h"
#include "utility.h"

struct contacts_t {
    size_t m_size;
    student_t* students;

public:
    contacts_t(size_t size)
     : m_size(size) {
        // When initializing, an students array of given size is declared.
        students = u::allocate<student_t>(m_size);

        // Set all student.id as -1
        for (size_t i = 0; i < m_size; i++) {
            students[i].id = -1;
        }
    }

    // OPTIONAL
    // You can write additional functions for code reuse.

    bool add(student_t student);
    bool add(int id, std::string name);
    bool add(int id, std::string name, std::string phone);
    bool add(int id, std::string name, std::string phone, std::string mail);

    bool remove(int id);

    bool update(int id, std::string name, std::string phone, std::string mail);

    student_t find(int id);

    size_t size();
};