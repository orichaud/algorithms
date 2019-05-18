#include <iostream>
#include <vector>
#include <bitset>
#include <tuple>

using namespace std;

const unsigned int bits = 8;

unsigned long brute_force_swap(unsigned long x, unsigned short i, unsigned short j) {
    unsigned long y = x;
    // swap ith and jth bits differ
    if( ((x >> i) & 1) != ((x >> j) & 1) ) {
        unsigned mask = (1 << i) | (1 << j); // create mask with bits on
        y = x ^ mask; // it works because bits are different
    }
    return y;
}

int main()
{
    typedef tuple<unsigned long, unsigned short, unsigned short> value;   
    vector<value> values = {
        make_tuple(0b11000000, 1, 7),
        make_tuple(0b11000001, 1, 7),
        make_tuple(0b00000001, 0, 1)
    };
    for(const auto& value: values) {
        auto x = get<0>(value);
        auto i = get<1>(value);
        auto j = get<2>(value);
        auto y = brute_force_swap(x, i, j);
        cout << "x=" << bitset<bits>(x) 
             << ", brute_force_swap with i=" << i << ",j=" << j << "= " <<  bitset<bits>(y)
             << endl;
    }
}