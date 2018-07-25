#include <iostream>
#include <algorithm>

using namespace std;

int constInt[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    bool flag = false;
    do {
        if ((constInt[0] * 100 + constInt[1] * 10 + constInt[2]) * B ==
            (constInt[3] * 100 + constInt[4] * 10 + constInt[5]) * A &&
            (constInt[0] * 100 + constInt[1] * 10 + constInt[2]) * C ==
            (constInt[6] * 100 + constInt[7] * 10 + constInt[8]) * A &&
            (constInt[3] * 100 + constInt[4] * 10 + constInt[5]) * C ==
            (constInt[6] * 100 + constInt[7] * 10 + constInt[8]) * B) {
            cout << constInt[0] * 100 + constInt[1] * 10 + constInt[2] << " "
                 << constInt[3] * 100 + constInt[4] * 10 + constInt[5] << " "
                 << constInt[6] * 100 + constInt[7] * 10 + constInt[8] << endl;
            flag = true;
        }
    } while (next_permutation(constInt, constInt + 9));
    if (!flag) {
        cout << "No!!!";
    }
}
