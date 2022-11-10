#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

namespace Michael {
    template <typename T>
    class stack {
    private:
        size_t capacity = 10;
        vector<T> mydata;
    public:
        stack() {mydata.reserve(capacity);}
        ~stack() {}
        T top() {return mydata.at(mydata.size() - 1);}
        void pop() {
            if (empty()) {
                throw underflow_error("Stack underflowed!");
            }
            else {
                mydata.pop_back();
            }
        }
        void push(T t) {
            if (full()) {
                throw overflow_error("Stack overflowed!");
            }
            else {
                mydata.push_back(t);
            }
        }
        void clear() {mydata.clear();}
        size_t size() {return mydata.size();}
        bool full() const noexcept {return mydata.size() == capacity;}
        bool empty() const noexcept {return mydata.size() == 0;}
    };
}

int main() {
    Michael::stack<int> s;
    for (int i = 1; i <= 10;) {
        s.push(i);
        i+=1;
    }
    cout << s.size() << endl;
    cout << s.full() << endl;
    s.pop();
    cout << s.top() << endl;
    s.clear();
    cout << s.empty() << endl;
    return 0;
}