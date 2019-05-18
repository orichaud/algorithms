#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

const unsigned int bits = 8;

template <unsigned int bits>
unsigned long brute_force_reverse(unsigned long v) {
    unsigned long r = 0;
    // progressively build the 2 extremities ith and <bits>-i th positions
    // assuming even number of bits
    unsigned short n = bits / 2;
    for(unsigned int i = 0; i<n; ++i) {
        unsigned int j = bits - 1 - i;
        r |= (((v >> i) & 1) << j) | (((v >> j) & 1) << i); 
    }
    return r;
}

int main()
{
    vector<unsigned long> values = {
        0b11000000,
        0b00001011,
        0b00000010,
        0b00011101,
        0b00000111
    };
    for(const auto x: values) {
        cout << "x=" << bitset<bits>(x) 
             << ", brute_force_reverse = " <<  bitset<bits>(brute_force_reverse<bits>(x))
             << endl;
    }
}