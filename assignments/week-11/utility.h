#ifndef __UTILITY_H__
#define __UTILITY_H__

#include <iterator>

namespace util {
    static int index = 0;

    template<typename Iter>
    Iter select_randomly(Iter start, Iter end) {
        auto size = std::distance(start, end);
        std::advance(start, index % size);
        index += 1;
        return start;
    }
}

#endif
