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
	// copy constructor
	polynomial(const polynomial& p) : deg(p.deg), coef(p.coef) {}
	// move assignment operator
    polynomial& operator = (polynomial&& src) {
            assert(deg == 0 || deg == src.deg);
            swap(coef, src.coef);
            cout << "ok this works" << endl;
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

polynomial f(double c2, double c1, double c0) {
    vector<double> coef = {c0, c1, c2};
    return polynomial(2, coef);
}

int main() {
	polynomial p1;
	p1 = f(1.0, 2.0, 3.0);
    return 0;
}