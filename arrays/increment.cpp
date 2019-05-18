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

// increment an array representing a number by one: {1, 3, 9} becomes {1, 4, 0}
vect_t increment(const vect_t& vect) {
    if(vect.empty())
        return {};

    vect_t result(vect.begin(), vect.end()); // vector filled with input
    // perform increment of 1 of lowest digit and test if propagation is needed
    if(++result.back() >= 10) { 
        value_t carry_out = 0; // carry_out to be propagated
        auto end = result.rend(); 
        for(auto it = result.rbegin(); it != end; ++it) { // need to go in reverse order
            *it += carry_out;
            carry_out = *it >= 10 ? 1 : 0;
            if(!carry_out)
                break; // no need to continue and propagate
            // carry_out kicks in
            *it -= 10;
        }
        // add extra element if we reach the end and need extra digit
        if(carry_out > 0) { 
            result.insert(result.begin(), carry_out);
        }
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