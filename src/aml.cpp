#include <iostream>
#include <fstream>
#include <regex>
#include "aml.hpp"
#include "fa.hpp"
using namespace std;

bool isComment(string str) {
    // Find the first non-space character
    auto it = std::find_if(str.begin(), str.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    });

    // Check if the string starts with "//" after ignoring leading spaces
    return (it != str.end() && std::distance(it, str.end()) > 1 && *it == '/' && *(it + 1) == '/');
}


vector<string> gval_aml(string key, string file, size_t amount) {
    regex key_r("^" + key + "=");
    regex sp(" ");
    string ln;
    vector<string> ret_vec;
    ifstream fileTP(file);
    if (!fileTP.is_open()) {
        return vector<string>(1, "err");
    }
    while(getline(fileTP, ln)) {
        if (amount == 0) {
            amount = find_a(ln);
        }
        if (isComment(ln)) {
            cout << "yes" << "\n";
        }
        if (regex_search(ln, key_r)) {
            string ret_vp_ = regex_replace(ln, key_r, "");
            for (size_t i = 0; i < amount; i++) {
                size_t ret_find = ret_vp_.find(",");
                ret_vec.push_back(ret_vp_.substr(0, ret_find));
                ret_vp_.erase(0, ret_find+1);
            }
        }
    }
    fileTP.close();
    return ret_vec;
}
