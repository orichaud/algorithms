#include <iostream>
#include <unordered_map>

// Fibonacci number
// https://en.wikipedia.org/wiki/Fibonacci_number

using namespace std;

template <unsigned int N> struct fibo;

// static template instantiation will allow compile time computation of Fibo(n)

template <> struct fibo<0> {
    static const unsigned int n = 0;
    static const unsigned int value = 0;
};

template <> struct fibo<1> {
    static const unsigned int n = 1;
    static const unsigned int value = 1;
};

template <unsigned int N> struct fibo {
    static const unsigned int n = N;
    static const unsigned int value = fibo<N-1>::value + fibo<N-2>::value;
};

// Avoid recursion and reuse previous values during Fibo(n) computation

class fibo_compute {
public:
    typedef unsigned int value_type;

    fibo_compute() {
        values_[0] = 0;
        values_[1] = 1;
    }

    value_type operator [] (value_type n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        auto it = values_.find(n);
        if(it == values_.end()) {
            auto value = (*this)[n-2] + (*this)[n-1];
            values_[n] = value;
            return value;
        } else {
            return (*it).second;
        }
    }
private:
    unordered_map<value_type, value_type> values_;
};


int main()
{
    const unsigned int N = 100;
    cout << "f(" << fibo<N>::n << ")=" << fibo<N>::value << endl;
    fibo_compute fc;
    cout << "fibo_compute(" << N << ")=" << fc[N] << endl;
}
