#include <bits/stdc++.h>

using namespace std;
const int N = 5000 + 5;
bool cancle[N];

struct trade {
    double price;
    long long num;

    bool operator<(const trade &n) const {
        return price > n.price;
    }
} a[N];

priority_queue<trade> buy, sell;

int main() {
    memset(cancle, false, sizeof(cancle));
    int no = 1;
    string s0;
    int v;
    while (cin >> s0) {
        if (s0[0] == 'c') {
            cin >> v;
            cancle[v] = true;
            cancle[no] = true;
        } else if (s0[0] == 'b' || s0[0] == 's') {
            cin >> a[no].price >> a[no].num;
            if (s0[0] == 'b')
                a[no].price = -a[no].price;
        }
        no++;
    }
    trade t;
    t.price = 0.0;
    t.num = 0;
    for (int i = 1; i < no; i++) {
        if (cancle[i]) continue;
        if (a[i].price < 0.0) {
            buy.push(a[i]);
        } else
            sell.push(a[i]);
    }
    for (;;) {
        if (buy.empty() || sell.empty()) break;
        trade b = buy.top(), s = sell.top();
        buy.pop();
        sell.pop();
        if (-b.price >= s.price) {
            long long k = min(b.num, s.num);
            t.num += k;
            t.price = -b.price;
            b.num -= k;
            s.num -= k;
            if (b.num > 0) buy.push(b);
            if (s.num > 0) sell.push(s);
        } else break;
    }
    printf("%.2f", fabs(t.price));
    cout << " " << t.num << endl;
    return 0;
}
