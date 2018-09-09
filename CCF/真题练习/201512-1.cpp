#include <bits/stdc++.h>

using namespace std;

int main() {
    int sum = 0;
    string str;
    cin >> str;

    for (int i = 0; i < str.size(); ++i) {
        sum += (str[i] - '0');
    }
    
    cout << sum;
}
