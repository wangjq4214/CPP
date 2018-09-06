#include <iostream>
#include <cstring>

using namespace std;

const long long MOD = 1000000007;
long long status[1010][6];


int main() {
    int n;

    cin >> n;

    memset(status, 0, sizeof(status));

    status[1][0] = 1;
    for (int i = 2; i <= n; i++) {
        status[i][0] = 1;// ֻ��������2
        status[i][1] = (status[i - 1][1] * 2 + status[i - 1][0]) % MOD;// ֻ��������2��0
        status[i][2] = (status[i - 1][2] + status[i - 1][0]) % MOD;// ֻ��������2��3
        status[i][3] = (status[i - 1][3] * 2 + status[i - 1][1]) % MOD;// ֻ��������2��0��1��������������0��1֮ǰ
        status[i][4] = (status[i - 1][4] * 2 + status[i - 1][1] + status[i - 1][2]) % MOD;// ֻ��������2��0��3��������������2��3֮ǰ
        status[i][5] = (status[i - 1][5] * 2 + status[i - 1][3] + status[i - 1][4]) % MOD;// ������������
    }

    cout << status[n][5] << endl;

    return 0;
}

