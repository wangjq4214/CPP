#include <iostream>

using namespace std;

int main() {
    int cs[15][10];
    int bk[4][4];
    int hp;
    int x[4];
    int y[4];
    int a = 0;
    int b = 0;
    int k = 0;
    bool qr = true;

    //�õ���ʼ
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> cs[i][j];
        }
    }

    //�õ����
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> bk[i][j];
        }
    }

    cin >> hp;
    hp -= 1;

    //�õ����λ��
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (bk[i][j] == 1) {
                x[a] = i;
                y[a] = j + hp;
                a++;
            }
        }
    }

    //�³�
    while (qr) {
        for (int i = 0; i < 4; i++) {
            if (cs[x[i] + b][y[i]] == 0) {
                k++;
            }
        }
        if (k == 4) {
            b++;
            k = 0;
        } else {
            for (int i = 0; i < 4; i++) {
                cs[x[i] + b - 1][y[i]] = 1;
            }

            qr = false;
        }
    }

    //���
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 10; j++) {
            cout << cs[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
