#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

namespace Michael {
    template <typename T>
    class vector {
    private:
        size_t size;
        T* data;
    public:
        vector(initializer_list<T> k) {
           size = k.size();
           data = new T[size];
           copy(k.begin(), k.end(), begin());
        }
        ~vector() {delete[] data;}
        T* begin() {return data;}
        const T* begin() const noexcept {return data;}
        T* end() {return data + size;}
        const T* end() const noexcept {return data + size;}
    };
}

int main() {
    Michael::vector<int> v1{3,1,5,2,4};
    sort(v1.begin(), v1.end());
    cout << *(v1.begin()) << " " << *(v1.end() - 1);
    return 0;
}