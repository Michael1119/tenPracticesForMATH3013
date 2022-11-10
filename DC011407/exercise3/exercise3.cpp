#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class polynomial {
private:
	int deg;
	vector<double> coef;
public:
	polynomial() : deg(0) {}
	polynomial(int degree, vector<double> coefficient) : deg(degree), coef(coefficient) {
		assert(deg == coef.size()-1);
	}
	polynomial(const polynomial& p) : deg(p.deg), coef(p.coef) {} // copy constructor
	~polynomial() {}
	int get_deg() {return deg;}
	// move assignment operator
    polynomial& operator = (polynomial&& src) {
            assert(deg == 0 || deg == src.deg);
            swap(coef, src.coef);
            cout << "ok this works" << endl;
            return *this;
    }
	// friend is required for free function to access the private value p.coef
	friend ostream& operator << (ostream& os, const polynomial& p);
};

// free function because ostream& is not a member of the class polynomial
ostream& operator << (ostream& os, const polynomial& p) {
	for (auto i : p.coef) {
		os << i << " ";
	}
	return os;
}

polynomial f(double c2, double c1, double c0) {
    vector<double> coef = { c0,c1,c2 };
    return polynomial(2, coef);
}

int main() {
	int d1 = 2;
	vector<double> c1 = { 2.39,7.42,4.32 };
	polynomial p1(d1, c1);
	cout << "The degree of given polynomial is " << p1.get_deg() << " and the coefficients are " << "\n" << p1 << endl;
	polynomial p2;
	p2 = f(1.0, 2.0, 3.0);
    return 0;
}