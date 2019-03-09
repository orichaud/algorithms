#include <iostream>
#include <vector>
#include <algorithm>

template <typename It> void print(unsigned int round, It first, It last) {
    std::cout << round << ":\t";
    std::for_each(first, last, [](const auto& v) { std::cout << v << "\t"; });
    std::cout << std::endl;
}

// Insertion sort with STL
template <typename It> void insertion_sort(It first, It last) {
    unsigned int round = 0;
    for (auto i = first; i != last; ++i) {
        std::rotate(std::upper_bound(first, i, *i), i, std::next(i));
        print(round++, first, last);
    }
}

int main() {
    std::vector<int> values = { 78, 5, 2, 25, 4, 17, 11, 23, 18, 11,67, 0, -14 };
    
    insertion_sort(values.begin(), values.end());
    
    return 0;
}