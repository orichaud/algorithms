#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

const unsigned int bits = 8;

// the parity of of binary word is 1 if the number of 1s if odd and 0 otherwise. 

unsigned int brute_force_parity(unsigned long v) {
    unsigned int parity = 0;
    while(v != 0) {
        parity ^= (v & 1); // because of modulo 2
        v >>= 1;
    }
    return parity;
}

unsigned int brute_force_parity_improved(unsigned long v) {
    unsigned int parity = 0;
    while(v != 0) {
        parity ^= 1; // because modulo 2
        v &=  v - 1; // clear lowest bits of v, will lead to k (# of 1s ) loops
    }
    return parity;
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
             << ", brute_force_parity = " <<  brute_force_parity(x)
             << ", brute_force_parity_improved = " <<  brute_force_parity_improved(x)
             << endl;
    }
}