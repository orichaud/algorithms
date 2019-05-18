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
        0b00000111
    };
    for(const auto x: values) {
        unsigned long y = x & ~(x - 1);

        cout << "1 - x=" << bitset<bits>(x) 
             << ", (x -1) = " <<  bitset<bits>(x -1)
             << ", ~(x -1) = " <<  bitset<bits>(~(x -1))
             << ", x & ~(x - 1) = " << bitset<bits>(y) << endl;

        cout << "3 - x=" << bitset<bits>(x) 
             << ", x ^ 1 = " <<  bitset<bits>(x ^ 1) << endl;
    }
}