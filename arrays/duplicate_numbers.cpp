#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

typedef std::vector<int> vect_int;

// remove duplicated numbers from array

vect_int remove_duplicates(const vect_int& vect) {
    unordered_set<int> counters;
    vect_int result;
    for(auto v: vect) {
        auto found = counters.find(v);
        if(found == counters.end()) {
            result.push_back(v);
        }
    }
    return result;
}

ostream& operator << (ostream& os, const vect_int& vect) {
    os << "[ ";
    for(auto v: vect) {
        os << v << " ";
    }
    os << "]";
    return os;
}

int main() {
    vector<vect_int> vects = {
       {1, 3, 3, 14, 1, 17 },
       {1, 3, 3, 14, 1, 17, 100, 45, 3, 3, 3, 17 }
    };
    
    for(auto vect: vects) {
        cout << vect << " => " << remove_duplicates(vect) << endl;
    }
    return 0;
}