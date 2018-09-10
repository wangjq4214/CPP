#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, sum = 0;
    cin >> n;
    sum = (n / 50) * 7;
    n %= 50;
    sum += (n / 30) * 4;
    n %= 30;
    sum += n / 10;
    cout << sum;
}
