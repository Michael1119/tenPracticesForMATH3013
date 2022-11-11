#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<double> v1{-9.3, -7.4, -3.8, -0.4, 1.3, 3.9, 5.4, 8.2};
    sort(v1.begin(), v1.end(), [](double x, double y){return abs(x) < abs(y);});
    for (int i = 0; i < v1.size(); i++) {
        cout << v1[i] << " ";
    }
    return 0;
}