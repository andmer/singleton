#ifndef pair_pair_H
#define pair_pair_H

#include <ostream>
#include <algorithm>
#include <vector>

template <typename T, typename U>
struct pair {
private:
    T first;
    U second;

public:
    explicit
    pair() : first(), second() {
        printf("ctor0\n");
    }

    explicit
    pair(T t, U u) : first(t), second(u){
        printf("ctor1\n");
    }

    pair(const pair& x) : first(x.first), second(x.second) { printf("copy ctor0\n"); }

    /*
    template <typename U>
    pair(const pair<U>& x) : value(x.value) { printf("copy ctor1\n"); }
    */

    pair& operator=(const pair& x) {
        printf("assignment\n");
        //extra work, skip it, stepanov
        /*
        if (this == &x) {
            return *this;
        }
        */
        first = x.first;
        second = x.second;
        return *this;
    }

    ~pair() {
        printf("dtor\n");
    }

    friend
    bool operator<(const pair& x, const pair& y) {
        printf("comparison\n");
        return x.first < y.first && x.second < y.second;
    }

    friend
    bool operator>(const pair& x, const pair& y) {
        return x < y;
    }

    friend
    bool operator<=(const pair& x, const pair& y) {
        return !(x < y);
    }

    friend
    bool operator>=(const pair& x, const pair& y) {
        return !(y < x);
    }

    friend
    bool operator==(const pair& x, const pair& y) {
        printf("equality\n");
        return x.first == y.first && x.second == y.second;
    }

    friend
    bool operator!=(const pair& x, const pair& y) {
        return !(x == y);
    }

    friend
    std::ostream& operator<<(std::ostream& os, const pair& x) {
        return os << "pair: first= " << x.first << ", second= " << x.second << "\n";
    }
};

#endif //pair_pair_H
