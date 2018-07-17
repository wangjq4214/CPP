#include<iostream>

using namespace std;

enum Action {
    Up, Down, Left, Right
};

int main() {
    int n;
    cin >> n;
    int table[n + 2][n + 2];
    for (int i = 0; i <= n + 1; i++)
        for (int j = 0; j <= n + 1; j++) {
            if (i == 0 || j == 0 || i == n + 1 || j == n + 1)
                table[i][j] = -1;
            else
                table[i][j] = 0;
        }
    int x, y;
    Action act;
    if (n % 2 == 1) {
        act = Left;
        x = 1;
        y = n;
    } else if (n % 2 == 0) {
        act = Right;
        x = n;
        y = 1;
    }
    for (int count = n * n; count != 0; --count) {
        table[x][y] = count;
        if (act == Left) {
            if (table[x - 1][y] != 0) {
                act = Down;
                y--;
            } else
                x--;
        } else if (act == Right) {
            if (table[x + 1][y] != 0) {
                act = Up;
                y++;
            } else
                x++;
        } else if (act == Up) {
            if (table[x][y + 1] != 0) {
                act = Left;
                x--;
            } else
                y++;
        } else if (act = Down) {
            if (table[x][y - 1] != 0) {
                act = Right;
                x++;
            } else
                y--;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << table[i][j];
            if (j != n)
                cout << ' ';
        }
        cout << endl;
    }
    return 0;
}

