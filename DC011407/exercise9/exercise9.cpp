#include <map>
#include <string>
#include <iostream>

using namespace std;

int main() {
    map<string, unsigned long> phone_numbers = {{"Michael", 28111111}, {"Henry", 28222222}, {"Sam", 28333333}, {"Jay", 28444444}, {"Luiz", 28555555}, {"Cathy", 28666666}};
    string key;
    cout << "Input the name: ";
    cin >> key;
    auto it = phone_numbers.find(key);
    if (it == phone_numbers.end()) {
        cout <<"You don't have " << key << "'s phone number" << endl;
    }
    else {
        cout << key << "'s phone number is " << it->second << endl;
    }
    return 0;
}