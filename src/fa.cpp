#include <iostream>
#include <string>
#include "fa.hpp"
using namespace std;

size_t find_a(string str) {
    size_t amt = 0;
    while (str.length() != 0) {
        size_t index = str.find(",");
        if (index > str.size()) {
            amt++;
            str.erase(0, str.size());
        } else {
            amt++;
            str.erase(0, index+1);
        }
    }
    return amt;
}
