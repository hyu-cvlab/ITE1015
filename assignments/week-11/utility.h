#ifndef __UTILITY_H__
#define __UTILITY_H__

#include <random>
#include <iterator>

namespace util_back {
    template<typename Iter, typename Generator>
    Iter select_randomly(Iter start, Iter end, Generator& g) {
        std::uniform_int_distribution<> dis(0, std::distance(start, end) - 1);
        std::advance(start, dis(g));
        return start;
    }

    template<typename Iter>
    Iter select_randomly(Iter start, Iter end) {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        return select_randomly(start, end, gen);
    }
}

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
