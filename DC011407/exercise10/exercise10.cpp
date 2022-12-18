#include <iostream>

using namespace std;

namespace Michael {
    template <typename T>
    class vector_expression{
    public:
        unsigned int size(){return my_size;}
        T& operator () (unsigned int i){
            return data[i];
        }
    protected:
        vector_expression(){}
        ~vector_expression(){}
        unsigned int my_size;
        T* data;
    };

    // this-> can be replaced by vector_expression<T>::
    template <typename T>
    class vector : public vector_expression<T> {
    public:
        vector(initializer_list<T> k) {
           this->my_size = k.size();
           this->data = new T[this->my_size];
           copy(k.begin(), k.end(), begin());
        }
        ~vector() {delete[] this->data;}
        T* begin() {return this->data;}
        const T* begin() const noexcept {return this->data;}
        T* end() {return this->data + this->my_size;}
        const T* end() const noexcept {return this->data + this->my_size;}
    };

    class ones : public vector_expression<int>{
    public:
        ones(unsigned int length){
            my_size = length;
            data = new int[my_size];
            for(int i = 0; i < my_size; ++i){
                data[i] = 1;
            }
        }
        ~ones() {delete[] data;}
    };
}

using namespace Michael;

int main(){
    vector<int> a{1,3,5};
    ones b(4);
    cout << a.size() << endl;
    cout << a(0) << " " << a(1) << " " << a(2) << endl;
    cout << b.size() << endl;
    cout << b(0) << " " << b(1) << " " << b(2) << " " << b(3) << endl;
    return 0;
}