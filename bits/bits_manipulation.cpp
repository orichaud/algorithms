#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

const unsigned int bits = 8;

int main()
{
    vector<unsigned long> values = {
        0b00101100,
        0b00000010,
        0b00011100,
        0b00000111,
        0b10000100
    };
    for(const auto x: values) {
        // keep lowest bit to 1, remove all above 
        cout << "1 - x=" << bitset<bits>(x) 
             << ", (x - 1) = " <<  bitset<bits>(x -1)
             << ", ~(x - 1) = " <<  bitset<bits>(~(x -1))
             << ", x & ~(x - 1) = " << bitset<bits>(x & ~(x - 1)) << endl;

        // clear lowest bit set to 1, keep all above
        cout << "2 - x=" << bitset<bits>(x) 
             << ", (x - 1) = " <<  bitset<bits>(x -1)
             << ", x & (x - 1) = " << bitset<bits>(x & (x - 1)) << endl;
    }
}