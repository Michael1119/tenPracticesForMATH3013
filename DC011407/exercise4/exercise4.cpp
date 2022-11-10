#include <iostream>
#include <vector>
#include <cassert>
#include <initializer_list>

using namespace std;

class polynomial {
private:
	int deg;
	vector<double> coef;
public:
	polynomial() : deg(0) {}
	polynomial(int degree, vector<double> coefficient) : deg(degree), coef(coefficient) {
		assert(deg == coef.size() - 1);
	}
	~polynomial() {}
	// constructor for initializer list
    polynomial(initializer_list<double> j) {
        coef.assign(j.begin(), j.end());
        deg = j.size() - 1;
    }
    // assignment operator for initializer list
    polynomial& operator = (initializer_list<double> j) {
        coef.assign(j.begin(), j.end());
        deg = j.size() - 1;
        return *this;
    }
	// friend is required for free function to access the private value p.coef
	friend ostream& operator << (ostream& os, const polynomial& p);
public:
	int get_deg() {return deg;}
};

// free function because ostream& is not a member of the class polynomial
ostream& operator << (ostream& os, const polynomial& p) {
	for (auto i : p.coef) {
		os << i << " ";
	}
	return os;
}

int main() {
	polynomial p1{4.03, 4.77, 9.62};
    polynomial p2 = {8.07, 1.63, 5.08, 3.94};
    cout << p1.get_deg() << "\n" << p1 << endl;
    cout << p2.get_deg() << "\n" << p2 << endl;
}