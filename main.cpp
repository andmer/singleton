#include <cstdio>
#include <boost/regex.hpp>
#include <string>
#include <iostream>
#include "pair.h"
#include "singleton.h"

int main() {
    using sint = singleton<int>;
    using pint = pair<int, int>;
    pint p;
    pint p2(1, 2);
    p = p2;
    pint p3(p2);
}