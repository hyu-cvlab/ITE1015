#include <cassert>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include "../vector.h"

using namespace std;

class Test {
    std::string name;
public:
    Test()
    : name("") {

    }
    Test(const std::string& name)
    : name(name) {

    }

    friend ostream &operator<<(ostream &out, const Test &t);
    friend istream &operator>>(istream &in, const Test &t);
};

ostream &operator<<(ostream &out, const Test &t) {
    out << t.name;
    return out;
}
istream &operator>>(istream &in, const Test &t) {
    in >> t.name;
    return in;
}

int main() {
    {
        std::vector<std::string> strings{"1", "2", "3", "4", "5"};
        std::stringstream ss_in;
        std::stringstream ss_out;
        Vector<std::string> v;

        for (const auto& string : strings) {
            ss_in << string << " ";
        }

        while (ss_in >> v);

        ss_out << v;

        assert(v.size() == 5);
        assert(ss_out.str() == "1,2,3,4,5,");
    }

    return 0;
}
