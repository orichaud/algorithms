#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

typedef int value_t;
typedef std::vector<value_t> vect_t;

// remove duplicated numbers from array
// no sorting so space is O(number of unique values)
vect_t remove_duplicates(const vect_t& vect) {
    unordered_set<value_t> counters;
    vect_t result;
    for(const auto& v: vect) {
        auto found = counters.find(v);
        if(found == counters.end()) {
            result.push_back(v);
            counters.emplace(v);
        }
    }
    return result;
}

ostream& operator << (ostream& os, const vect_t& vect) {
    os << "[ ";
    for(auto v: vect) {
        os << v << " ";
    }
    os << "]";
    return os;
}

int main() {
    vector<vect_t> vects = {
       {1, 3, 3, 14, 1, 17 },
       {1, 3, 3, 14, 1, 17, 100, 45, 3, 3, 3, 17 }
    };
    
    for(auto vect: vects) {
        cout << vect << " => " << remove_duplicates(vect) << endl;
    }
    return 0;
}