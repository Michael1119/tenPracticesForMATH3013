#include <iostream>
#include <fstream>

using namespace std;

int main() {
	cout << "What is your age?";
	int age;
	cin >> age;
	ofstream file("age.txt");
	file << age;
	return 0;
}