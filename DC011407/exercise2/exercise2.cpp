#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class polynomial {
private:
	int deg;
	vector<double> coef;
public:
	polynomial() : deg(0) {};
	polynomial(int degree, vector<double> coefficient) : deg(degree), coef(coefficient) {
		assert(deg == coef.size()-1);
	}
	~polynomial() {};
	// friend is required for free function to access the private value p.coef
	friend ostream& operator << (ostream& os, const polynomial& p);
public:
	int get_deg() {return deg;};
};

// free function because ostream& is not a member of the class polynomial
ostream& operator << (ostream& os, const polynomial& p) {
	for (auto i : p.coef) {
		os << i << " ";
	}
	return os;
}

int main() {
	int d1 = 2;
	vector<double> c1 = { 2.39,7.42,4.32 };
	polynomial p1(d1, c1);
	cout << p1.get_deg() << "\n" << p1 << endl;
	return 0;
}