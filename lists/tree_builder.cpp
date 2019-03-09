#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

using namespace std;

template <typename T, unsigned int N> struct node {
    typedef node<T, N> node_t;
    
    T data;
    array<node_t*, N> children;

    ostream & dump(ostream&  os, int depth) const {
        auto fpad = [] (int depth) -> string { 
            string s;
            for(int i=0; i<depth; ++i)
                s+="\t";
            return s;
        };  
        const string pad = fpad(depth + 1);
        const string padclosed = fpad(depth);

        os << "[this=" << this << ", data=" << data << ", " << endl;
        for(unsigned int i=0; i<N;++i) {
            os << pad << i << " = ";
            node_t* n = children[i];
            if(n != nullptr) 
                n->dump(os, depth + 1);
            else 
                os << "null";
            if( i < N - 1) 
                os << ", " << endl;
        }
      
        os << endl << padclosed <<  "]" ;
        return os;
    }

    void list(vector<T>& values) const {
        for(auto n: children) {
            if(n != nullptr) 
                n->list(values);
        }
        values.push_back(data);
    }
};

template <typename T> class tree {
private:
    typedef node<T, 2> node_t;
    typedef node_t* node_ptr;

    node_ptr root;

protected:
    node_ptr build(const vector<T>& values, int start, int end) {
        if(start > end)
            return nullptr;
        int mid = (start + end) / 2;
        node_ptr n = new node_t { 
            data: values[mid], 
            children: { build(values, start, mid - 1),  build(values, mid + 1, end) }
        };
        return n;
    }

public:
    tree(): root(nullptr) {}

    template <typename X> friend ostream& operator << (ostream& os, const tree<X>& t);

    ostream& dump(ostream& os) const {
        if(root != nullptr)
            root->dump(os, 0);
        return os;
    }

    void fill(const vector<T>& values) {
        root = build(values, 0, values.size() - 1);
    }

    void list(vector<T>& values) {
        if(root != nullptr)
            root->list(values);
    }
};

template<typename T> ostream& operator << (ostream& os, const tree<T>& t) {
    return t.dump(os);
}

int main()
{
    typedef tree<int> itree;
    typedef vector<int> ivector;
    ivector values = { 1, 2, 3, 4, 5 };
    itree t;
    t.fill(values);
    cout << t << endl;
    ivector out;
    t.list(out);
    for(auto v: out) cout << v  << " ";
}