#include <iostream>

using namespace std;

int main() {
    string str;
    getline(cin, str);
    for (int i = 0; i < str.size(); ++i) {
        if (islower(str[i])) {
            cout << char(toupper(str[i]));
        } else{
            cout << str[i];
        }
    }
}
