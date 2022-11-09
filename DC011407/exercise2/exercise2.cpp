#include <iostream>
#include <vector>

using namespace std;

class polynomial {
private:
	int deg;
	vector<double> coef;
public:
	polynomial() {};
	polynomial(int degree, vector<double> coefficient) : deg(degree), coef(coefficient) {} // initialize deg and coef
	~polynomial() {};
	int get_deg() {return deg;};
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

int main() {
	vector<double> c1 = { 2.39,7.42,4.32 };
	int d1 = 3;
	polynomial p1(d1, c1);
	cout << "The degree of given polynomial is " << p1.get_deg() << " and the coefficients are " << "\n" << p1 << endl;
	return 0;
}