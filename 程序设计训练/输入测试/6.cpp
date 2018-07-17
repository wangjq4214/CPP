#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    cin.get();
    string str[n];
    for (int i = 0; i < n; ++i) {
        getline(cin, str[i]);
    }

    string temp;
    cin >> temp;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        if (str[i].find(temp) != string::npos) {
            sum++;
        }
    }
    cout << sum;
}
