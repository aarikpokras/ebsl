#include <iostream>
#include <fstream>
#include <regex>
#include "aml.hpp"
#include "fa.hpp"
using namespace std;

vector<string> gval_aml(string key, string file, size_t amount) {
    regex key_r("^" + key + "=");
    regex sp(" ");
    string ln;
    vector<string> ret_vec;
    ifstream fileTP(file);
    if (!fileTP.is_open()) {
        ret_vec.push_back("err");
        return ret_vec;
    }
    while(getline(fileTP, ln)) {  // On condition that file is opened, so it is fine to use ret_vec
        if (amount == 0) {
            amount = find_a(ln);
        }
        if (regex_search(ln, key_r)) {
            string ret_vp_ = regex_replace(ln, key_r, "");
            for (size_t i = 0; i < amount; i++) {
                size_t ret_find = ret_vp_.find(",");
                ret_vec.push_back(ret_vp_.substr(0, ret_find));
                ret_vp_.erase(0, ret_find+1);
            }
        } else {
            ret_vec.push_back("key_err");
            return ret_vec;  // Return right here is not necessary as the file is already opened.
                             // This would be bad if the file wasn't opened, hence the immediate
                             // return in the file-is-open checker. This is here for compatibility
                             // to be tested in CI later.
        }
    }
    fileTP.close();
    return ret_vec;
}
