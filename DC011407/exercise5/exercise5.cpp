#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class stack {
private:
    size_t capacity = 20;
    vector<T> mydata;
    bool full() const noexcept {return mydata.size() == capacity;}
    bool empty() const noexcept {return mydata.size() == 0;}
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
    void push() {
        if (full()) {
            throw overflow_error("Stack overflowed!");
        }
        else {
            mydata.push_back();
        }
    }
    void clear() {mydata.clear();}
    size_t size() {return mydata.size();}
};

int main() {
    return 0;
}