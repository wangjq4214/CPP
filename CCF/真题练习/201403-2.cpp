#include <bits/stdc++.h>
using namespace std;
struct win {
    int x1, y1;
    int x2, y2;
} graph[10];

int main() {
    int n, m, num[10];
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        num[i] = n - i - 1; //´¢´æ±àºÅË³Ðò
        cin >> graph[i].x1 >> graph[i].y1 >> graph[i].x2 >> graph[i].y2;
    }
    int x, y;
    for (int i = 0; i < m; i++) {
        bool flag = true;
        cin >> x >> y;
        for (int j = 0; j < n; j++) //°´Ë³Ðò±éÀú
            if (graph[num[j]].x1 <= x && graph[num[j]].x2 >= x && graph[num[j]].y1 <= y && graph[num[j]].y2 >= y) {
                cout << num[j] + 1 << endl;
                flag = false;
                int v = num[j];   //µ÷Ë³Ðò
                for (int k = j; k > 0; k--)
                    num[k] = num[k - 1];
                num[0] = v;
                break;
            }
        if (flag)
            cout << "IGNORED" << endl;
    }
    return 0;
}
