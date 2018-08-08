#include <iostream>
#include <algorithm>

using namespace std;

struct Farm {
    int pi;
    int ai;
};

bool compare(const Farm &x, const Farm &y) {
    return x.pi < y.pi;
}

int main() {
    int n, m;
    cin >> n >> m;
    Farm farm[m];

    for (int i = 0; i < m; ++i) {
        cin >> farm[i].pi;
        cin >> farm[i].ai;
    }

    sort(farm, farm + m, compare);

    int sum = 0;
    for (int i = 0; i < m; ++i) {
        if (n - farm[i].ai <= 0) {
            sum += (n * farm[i].pi);
            break;
        } else {
            sum += (farm[i].ai * farm[i].pi);
            n -= farm[i].ai;
        }
    }
    
    cout << sum;
}
