#include <iostream>

using namespace std;

typedef long long ll;
ll memory[30][30][30] = {0};

ll w(ll a, ll b, ll c);


int main() {
    ll a, b, c;
    while (cin >> a >> b >> c && (a != -1 || b != -1 || c != -1)) {
        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << endl;
    }
}

ll w(ll a, ll b, ll c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        return 1;
    } else if (a > 20 || b > 20 || c > 20) {
        return w(20, 20, 20);
    } else if (memory[a][b][c]) {
        return memory[a][b][c];
    } else if (a < b && b < c) {
        memory[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    } else {
        memory[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
    }
    return memory[a][b][c];
}
