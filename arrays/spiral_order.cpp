#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

typedef size_t value_t;
typedef std::vector<value_t> row_t;
typedef std::vector<row_t> matrix_t;

ostream& operator << (ostream& os, const row_t& row) {
    for(auto cell: row) {
        os << setw(4) << cell;
    }
    return os;
}

ostream& operator << (ostream& os, const matrix_t& matrix) {
    auto end = matrix.end();
    for(auto it = matrix.begin(); it != end; ++it) {
        os  << *it;
        if(it != (end - 1)) 
            os << endl;
    }
    return os;
}

// create decreasing spiral matrix of order n
matrix_t spiral_order(size_t n) {
    matrix_t m(n, row_t(n, 0));
    for(size_t i = 0; i<n; ++i) {
        row_t& row = m[i];
        for(size_t j = 0; j<n; ++j) {
            // x stores the layer in which (i, j)th element lies
            value_t x = min(min(i, j), min(n-1-i, n-1-j)); 
            // i<=j for for upper right half
            // otherwise will deal with the bottom
            row[j] = (i <= j) ? (n-2*x)*(n-2*x) - (i-x) - (j-x) : (n-2*x-2)*(n-2*x-2) + (i-x) + (j-x);
        }
    }
    return m;
}

void internal_recursive_spiral_order(matrix_t& m, size_t size, value_t value) {
    if(size < 1)
        return;

    size_t row = (m.size() - size) / 2;
    size_t col = row;
    if(size == 1){
        m[row][col] = value;
        return;
    }
    for(size_t i=0; i<size-1; ++i)
        m[row][col++] = value++; // Right
    for(size_t i=0; i<size-1; ++i)
        m[row++][col] = value++; // Down
    for(size_t i=0; i<size-1; ++i)
        m[row][col--] = value++; // left
    for(size_t i=0; i<size-1; ++i)
        m[row--][col] = value++; // Up

    internal_recursive_spiral_order(m, size-2, value);
}

matrix_t recursive_spiral_order(value_t n) {
    matrix_t m(n, row_t(n, 0));
    internal_recursive_spiral_order(m, m.size(), n);
    return m;
}

int main() {
    value_t order = 3;
    cout << "recursive (the simplest way)" << endl;
    cout << spiral_order(order) << endl;
    cout << endl;
    cout << "iterative (the hard way)" << endl;
    cout << spiral_order(order) << endl;
    return 0;
}