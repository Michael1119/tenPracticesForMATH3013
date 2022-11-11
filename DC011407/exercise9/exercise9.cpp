#include <map>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    map<string, unsigned long> phone_numbers = {{"Michael", 28111111}, {"Henry", 28222222}, {"Sam", 28333333}, {"Jay", 28444444}, {"Luiz", 28555555}, {"Cathy", 28666666}};
    for (auto it = phone_numbers.begin(); it != phone_numbers.end(); ++it) {
        cout << it->first << " : " << it->second << endl;
    }
    string key = "!@#$";
    cout << "Input the name: ";
    cin >> key;
    auto iter = phone_numbers.find(key);
    if (iter == phone_numbers.end()) {
        cout <<"You don't have " << key << "'s phone number" << endl;
    }
    else {
        cout << key << "'s phone number is " << iter->second << endl;
    }
    return 0;
}