#include <iostream>
#include <vector>

using namespace std;

class Polynomial {
protected:
	int degree{}; //In-class initialization
	vector<double> coefficient{};

public:
	Polynomial() {};
	Polynomial(int deg, vector<double> coef) : degree(deg), coefficient(coef) {}
	~Polynomial() {};
	//Output 
	friend ostream& operator << (ostream& out, const Polynomial& express)
	{
		for (auto i : express.coefficient) {
			out << i << " ";
		}
		return out;
	}
};
int main() {
	vector<double> c1 = { 46.12,12.32,12.78 }; //Just for example
	int d1 = 3;
	Polynomial p1(d1, c1);
	cout <<"The degree of given polynomial is "<<d1<<
		" and the coefficient is "<<"\n" << p1 << endl;
	return 0;
}