#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

void duplicate_removal(string& s) {
    const size_t bits = sizeof(string::value_type);
    bitset<bits> letters;
    size_t newSize = 1;
    const auto b = s.begin();
    letters[*b] = true;
    for_each(b, s.end(), [&] (auto c) {
        if(letters[c]) return;
        *(b + newSize++) = c;
        letters[c] = true;
    });
    s.resize(newSize);
}

int main() {
vector<string> strs = {
        "",
        "a",
        "ab",
        "aa",
        "ababac",
        "abccba",
        "aaaaaaaaaaz"
    };

    for(auto s: strs) {
        cout << s << ":";
        duplicate_removal(s);
        cout << s << endl;
    }
    return 0;
}