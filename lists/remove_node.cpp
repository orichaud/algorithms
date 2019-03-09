#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T> struct node {
    T data;
    node<T> *next;
    bool mark_deleted;
};

template<typename T> ostream& operator << (ostream& os, const node<T>& n) {
    os << "[this=" << &n << ", data=" << n.data << ", next=" << n.next << ", mark_deleted=" << n.mark_deleted << "]";
    return os;
}

template <typename T> void chain(vector<node<T>* >& nodes) {
    auto end = nodes.end();
    for(auto it = nodes.begin();it!=end; ++it) {
         (*it)->next = (it + 1 == end) ? nullptr : *(it + 1);
    }
}

template <typename T> bool remove(node<T>* n) {
    if(n == nullptr || n->next == nullptr) // corner case, we cannot remove the last one without the "previous" pointer
        return false;
    n->data = n->next->data;
    n->next->mark_deleted = true;
    n->next = n->next->next;
    return true;
}

int main()
{
    typedef node<string> snode;
    vector<snode*> nodes = {
        new snode { data: "a", next: nullptr, mark_deleted: false }, 
        new snode { data: "b", next: nullptr, mark_deleted: false },
        new snode { data: "c", next: nullptr, mark_deleted: false },
        new snode { data: "d", next: nullptr, mark_deleted: false },
        new snode { data: "e", next: nullptr, mark_deleted: false }
    };

    auto print = [] (snode *n) {  cout << "\t" << *n << endl; };

    cout << "unchained: " << endl;
    for_each(nodes.begin(), nodes. end(), print);

    chain(nodes);

    cout << "chained: " << endl;
    for_each(nodes.begin(), nodes. end(), print);

    remove(nodes[2]);
    
    cout << "after removal: " << nodes[2] << endl;
    for_each(nodes.begin(), nodes. end(), print);
        cout << "traversal: " << endl;
    for(snode* head = nodes[0]; head != nullptr; head = head->next) {
        print(head);
    }
}