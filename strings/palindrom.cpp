#include <iostream>
#include <vector>

using namespace std;

// Check the string is an palindrom
bool is_palindrom(const string& s) {
    const size_t sz = s.size() - 1;
    const size_t n = sz / 2;
    for(size_t i = 0; i < n; ++i) {
        if(s[i] != s[sz - i])
            return false;
    }
    return true;
}

int main() {
    vector<pair<string, bool>> strs = {
       make_pair("aba", true),
       make_pair("abc", false),
       make_pair("ooooo", true),
       make_pair("abba", true)
    };

    for(auto p: strs) {
        cout << "[" << p.first << ", " << (p.second ? "OK" : "KO") << "]: ";
        bool ok =  is_palindrom(p.first);
        cout << (ok? "OK" : "KO") << endl;
    }
    return 0;
}