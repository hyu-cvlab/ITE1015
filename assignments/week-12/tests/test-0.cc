#include <cassert>
#include <iostream>
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

    std::string get_name() const {
        return name;
    }
};

int main() {
    {
        Vector<int> v;

        assert(v.size() == 0);
        assert(v.empty());

        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        assert(v.size() == 3);
        assert(v[0] == 1);
        assert(v[1] == 2);
        assert(v[2] == 3);
        assert(!v.empty());
        assert(v.capacity() >= v.size());
    }

    {
        Vector<Test> t;

        assert(t.size() == 0);
        assert(t.empty());

        t.push_back({"1"});
        t.push_back({"2"});
        t.push_back({"3"});
        assert(t.size() == 3);
        assert(t[0].get_name() == "1");
        assert(t[1].get_name() == "2");
        assert(t[2].get_name() == "3");
        assert(!t.empty());
        assert(t.capacity() >= t.size());
    }

    return 0;
}
