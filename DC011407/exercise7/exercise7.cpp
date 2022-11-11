#include <iostream>

namespace Michael {
    class odd_iterator {
    private:
        int i;
    public:
        odd_iterator() : i(1) {}
        odd_iterator(int k) {
            if (k%2 == 0) {
                throw "Cannot initialize with even numbers!";
            }
            else {
                i = k;
            }
        }
        odd_iterator(const odd_iterator& j) : i(j.i) {}
        odd_iterator& operator ++ () {
            i += 2;
            return *this; // returned value should be a reference to *this
        }
        odd_iterator operator ++ (int) {
            odd_iterator temp = *this;
            ++(*this);
            return temp; // returned value should be a copy of the object before increment
        }
        int operator * () {return i;}
        bool operator == (const odd_iterator& j) {return i == j.i;}
        bool operator != (const odd_iterator& j) {return i != j.i;}
        odd_iterator& operator = (const odd_iterator& j) {
            i = j.i;
            return *this;
        }
    };
}

using namespace std;
using namespace Michael;

int main() {
    odd_iterator a;
    cout << *a << endl; // 1

    odd_iterator b(3);
    cout << *b << endl; // 3

    odd_iterator c(b);
    ++(++c);
    cout << *c << endl; // 7. If & is not used in the pre-increment function then it returns 5 wrongly.
    cout << *(c++) << endl; // 7
    cout << *c << endl; // 9
    cout << (c != b) << endl; // 1
    c = b;
    cout << *c << endl; // 3
    cout << (c == b) << endl; // 1

    return 0;
}