#include <vector>
#include <iostream>
#include <bitset>

using namespace std;

// Check the string only contains unique characters

bool check(const string& s) {
    bitset<256> set;
    for(auto c: s) {
        if(set[c])
            return false;
        set.set(c);
    }
    return true;
}

int main() {
    vector<string> strs = {
        "abcdef",
        "abaa", 
        "12334aaa--"
    };
    
    for(auto s: strs) {
        cout << s << ":";
        cout << (check(s) ? "OK" : "KO") << endl;
    }
    return 0;
}