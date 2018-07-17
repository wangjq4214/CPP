#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

double finding(double *, double, double, int, int);

int main() {
    double q;
    int n;
    while (cin >> q >> n && n != 0) {
        // ÊäÈë¿ØÖÆ
        double spend[n];
        memset(spend, 0, sizeof(spend));
        for (int i = 0; i < n; ++i) {
            int m;
            cin >> m;
            double sum = 0;
            for (int j = 0; j < m; ++j) {
                char ch, rubbish;
                double price;
                cin >> ch >> rubbish;
                cin >> price;
                if (ch != 'A' && ch != 'B' && ch != 'C') {
                    sum = 0;
                    break;
                }
                if (price > 600) {
                    sum = 0;
                    break;
                }
                sum += price;
            }
            if (sum > 1000) {
                spend[i] = 0;
            } else {
                spend[i] = sum;
            }
        }

        double submiting = 0;
        double submit = finding(spend, submiting, q, n, 0);
        cout << setprecision(2) << fixed << submit << endl;
    }
}

double finding(double *spend, double submiting, double q, int n, int count) {
    if (submiting > q) {
        return -1;
    } else if (submiting == q) {
        return submiting;
    } else {
        double max = submiting;
        for (int i = count; i < n; ++i) {
            double temp;
            temp = finding(spend, submiting + spend[i], q, n, i + 1);
            if (temp > max) {
                max = temp;
            }
        }
        return max;
    }
}
