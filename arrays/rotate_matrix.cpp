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

// Process borders of the matrix (the x)
// x x x x
// x o o x
// x o o x
// x x x x
void internal_cycle(const matrix_t& in, size_t size, matrix_t& out) {
    const size_t row_offset = (in.size() - size) / 2;
    const size_t col_offset = row_offset;
    if(size == 1) {
        out[row_offset][col_offset] = in[row_offset][col_offset];
        return;
    }

    for(size_t i=0; i<size-1; ++i) {
        // upper row to last column
        out[row_offset + i][col_offset + size - 1] = in[row_offset][col_offset + i];
        // last column to last row in reverse order
        out[row_offset + size - 1][col_offset + size - 1 -i] = in[row_offset + i][col_offset + size - 1];
        // last row to first column in reverse order 
        out[row_offset + size - 1 - i][col_offset] = in[row_offset + size - 1 ][col_offset + size - 1 - i];
        // finally first column in reverse order to first row in order
        out[row_offset][col_offset + i] = in[row_offset + size - 1 - i][col_offset];
    }
}

void internal_recursive_rotate(const matrix_t& in, size_t size, matrix_t& out) {
    if(size < 1)
        return;

    // cycle around the border of the matrix
    internal_cycle(in, size, out);
    // extract englobed matrix
    internal_recursive_rotate(in, size-2, out);
}

matrix_t recursive_rotate(const matrix_t& in) {
    matrix_t out(in.size(), row_t(in.size(), 0));
    internal_recursive_rotate(in, in.size(), out);
    return out;
}

matrix_t rotate(const matrix_t& in) {
    matrix_t out(in.size(), row_t(in.size(), 0));
    // go from border to internal sub matrix
    for(size_t size = 0; size<in.size(); size -= 2) {
        if(size < 1)
            break;
        internal_cycle(in, size, out);
    }
    return out;
}

int main() {
    matrix_t m = {
        { 1, 2, 3, 4},
        { 5, 6, 7, 8},
        { 9, 10, 11, 12},
        { 13, 14, 15, 16}
    };
   
    cout << "recursive (the simple way)" << endl;
    cout << recursive_rotate(m) << endl;
    cout << endl;

    cout << "iterative (the faster way)" << endl;
    cout << recursive_rotate(m) << endl;
    cout << endl;
    return 0;
}