#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;
const int N = 100 + 10;
const int M = 100 + 10;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
char a[N][M];
int n, m, q;

void dfs(int x, int y, char c) { //填充操作
    a[x][y] = c;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= m || nx < 0 || ny >= n || ny < 0) continue; //越界
        if (a[nx][ny] == '+' || a[nx][ny] == '|' || a[nx][ny] == '-' || a[nx][ny] == c) continue; //碰到线段或者已经填充过
        dfs(nx, ny, c);
    }
}

int main() {
    int k, x1, y1, x2, y2;
    char c;
    scanf("%d%d%d", &n, &m, &q);
    memset(a, '.', sizeof(a));
    while (q--) {
        scanf("%d", &k);
        if (k) { //填充
            scanf("%d%d", &y1, &x1);
            getchar();
            c = getchar();
            dfs(x1, y1, c);
        } else {
            scanf("%d%d%d%d", &y1, &x1, &y2, &x2);
            if (x1 == x2) { //画横线
                if (y2 < y1) {
                    int t = y1;
                    y1 = y2;
                    y2 = t;
                }
                for (int i = y1; i <= y2; i++)
                    if (a[x1][i] == '|' || a[x1][i] == '+') a[x1][i] = '+'; //遇到交叉画十字
                    else a[x1][i] = '-';
            }
            if (y1 == y2) { //画竖线
                if (x2 < x1) {
                    int t = x1;
                    x1 = x2;
                    x2 = t;
                }
                for (int i = x1; i <= x2; i++)
                    if (a[i][y1] == '-' || a[i][y1] == '+') a[i][y1] = '+'; //遇到交叉画十字
                    else a[i][y1] = '|';
            }
        }
    }
    for (int i = m - 1; i >= 0; i--) { //输出
        for (int j = 0; j < n - 1; j++)
            printf("%c", a[i][j]);
        printf("%c\n", a[i][n - 1]);
    }
    return 0;
}
