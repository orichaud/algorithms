#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

// Check the string is an anagram
// The point is in the use of arrays to count occurrences.

bool anagram(const string& s1, const string& s2) {
    size_t l1 = s1.length();
    if(l1 != s2.length())
        return false;

    const size_t letters = sizeof(string::value_type);
    array<unsigned int, letters> a1, a2;
    a1.fill(0);
    a2.fill(0);
    for(size_t i = 0; i<l1; ++i) {
        a1[s1[i]]++;
        a2[s2[i]]++;
    }
    for(size_t i=0; i<letters; ++i) {
        if(a1[i] != a2[i])
            return false;
    }
    return true;
}

int main() {
    vector<pair<string, string>> strs = {
       make_pair("ab", "a"),
       make_pair("abc", "bca"),
       make_pair("ooooo", "ooooo")
    };

    for(auto p: strs) {
        cout << "[" << p.first << ", " << p.second << "]: ";
        bool ok =  anagram(p.first, p.second);
        cout << (ok? "OK" : "KO") << endl;
    }
    return 0;
}