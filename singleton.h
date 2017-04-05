#ifndef SINGLETON_SINGLETON_H
#define SINGLETON_SINGLETON_H

#include <ostream>
#include <algorithm>
#include <vector>

template <typename T>
struct singleton {
private:
    typedef T value_type;
    T value;

public:

    explicit
    operator T() const { return value; }

    explicit
    singleton() : value() {
        printf("ctor0\n");
    }

    explicit
    singleton(T t) : value(t) {
        printf("ctor1\n");
    }

    singleton(const singleton& x) : value(x.value) { printf("copy ctor0\n"); }

    template <typename U>
    singleton(const singleton<U>& x) : value(x.value) { printf("copy ctor1\n"); }

    singleton& operator=(const singleton& x) {
        printf("assignment\n");
        //extra work, skip it, stepanov
        /*
        if (this == &x) {
            return *this;
        }
        */
        value = x.value;
        return *this;
    }

    ~singleton() {
        printf("dtor\n");
    }

    friend
    bool operator<(const singleton& x, const singleton& y) {
        printf("comparison\n");
        return x.value < y.value;
    }

    friend
    bool operator>(const singleton& x, const singleton& y) {
        return x < y;
    }

    friend
    bool operator<=(const singleton& x, const singleton& y) {
        return !(x < y);
    }

    friend
    bool operator>=(const singleton& x, const singleton& y) {
        return !(y < x);
    }

    friend
    bool operator==(const singleton& x, const singleton& y) {
        printf("equality\n");
        return x.value == y.value;
    }

    friend
    bool operator!=(const singleton& x, const singleton& y) {
        return !(x == y);
    }

    friend
    std::ostream& operator<<(std::ostream& os, const singleton& singleton1) {
        return os << "value: " << singleton1.value << "\n";
    }
};

#endif //SINGLETON_SINGLETON_H
