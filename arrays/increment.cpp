#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

typedef unsigned int value_t;
typedef std::vector<value_t> vect_t;

ostream& operator << (ostream& os, const vect_t& vect) {
    os << "[ ";
    for(auto v: vect) {
        os << v << " ";
    }
    os << "]";
    return os;
}

// imcrement an array representing a number by one: {1, 3, 9} becomes {1, 4, 0}

vect_t increment(const vect_t& vect) {
    if(vect.empty())
        return {};

    vect_t result(vect.size(), 0); // vector filled with 0
    result.back()++; // perform increment of 1
    value_t carry_out = 0; // carry_out to be propagated
    auto r = result.end() - 1;
    auto end = vect.rend(); 
    for(auto it = vect.rbegin(); it != end; it++, r--) {
        auto v = *r + *it + carry_out;
        if(v >= 10) { // if carry_out kicks in
            carry_out = 1;
            v -= 10;
        } else {
            carry_out = 0; // otherwise clear
        }
        *r = v;
    }
    // add extra element if 
    if(carry_out > 0) { 
        result.insert(result.begin(), carry_out);
    }
    return result;
}

int main() {
    vector<vect_t> vects = {
       {1, 3, 9 },
       {9, 9, 9},
       {9, 0, 0},
       {9, 9, 1, 9}
    };
    
    for(auto vect: vects) {
        cout << vect << " => " << increment(vect) << endl;
    }
    return 0;
}