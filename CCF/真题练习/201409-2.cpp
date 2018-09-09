#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
const int N = 100 + 10;
bool vis[N][N], n;

int main() {
    int a, b, c, d;
    int ans = 0;
    memset(vis, false, sizeof(vis));
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        for (int i = a; i < c; i++)
            for (int j = b; j < d; j++)
                if (!vis[i][j]) //Ã»ÓÐÉ¨Ãè¹ý£¬ans+1 
                {
                    vis[i][j] = true;
                    ans++;
                }
    }
    printf("%d\n", ans);
    return 0;
}
