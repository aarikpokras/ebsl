#include <iostream>
#include <fstream>
#include <regex>
#include "aml.hpp"
using namespace std;

int main(int argc, char *argv[]) {
    regex key("^key=");
    regex fil("^file=");
    regex amt("^amt=");
    string key_, fil_;
    size_t amt_;
    if (argc > 1) {
        for (int i = 1; i < argc; i++) {
            if (regex_search(argv[i], key)) {
                key_ = regex_replace(argv[i], key, "");
            } else if (regex_search(argv[i], fil)) {
                fil_ = regex_replace(argv[i], fil, "");
            } else if (regex_search(argv[i], amt)) {
                string amt__ = regex_replace(argv[i], amt, "");
                amt_ = stoi(amt__);
            }
        }
        vector<string> out_x = gval_aml(key_, fil_, amt_);
        if (out_x[0] != "err") {
            for (size_t i = 0; i < out_x.size(); i++) {
                cout << out_x[i] << " ";
            }
        } else {
            cout << "An error occurred.";
        }
    } else {
        cout << "Usage: " << argv[0] << " key=[key] file=[file] amt=[amount]" << endl;
        return 1;
    }
    return 0;
}
