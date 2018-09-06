#include<iostream>
#include <cstring>

using namespace std;
const int N = 26;
int type[N]; //0代表不存在，1代表不带参数选项，2代表带参数选项
bool vis[N]; //访问标记
string para[N]; //参数
int main() {
    int n;
    string order, c;
    cin >> order;
    int l = order.length();
    memset(type, 0, sizeof(type));
    //保存选项类型
    for (int i = 0; i < l; i++) {
        int k = order[i] - 'a';
        if (order[i + 1] == ':') {
            type[k] = 2;
            i++;
        } else type[k] = 1;
    }
    cin >> n;
    getchar();
    for (int kase = 1; kase <= n; kase++) {
        memset(vis, false, sizeof(vis));
        getline(cin, order);
        int v = -1; //-1代表接下来是应该是选项，其他数代表接下来应该是参数
        int t = 0;
        l = order.length();
        while (order[t] != ' ' && t < l) {
            t++;
        } //略去ls
        t++;
        for (; t < l;) {
            c = "";
            while (order[t] != ' ' && t < l) {
                c += order[t++];
            }
            if (v == -1) //输入并判断选项
            {
                if (c.length() == 2 && c[0] == '-' && islower(c[1])) {
                    v = c[1] - 'a';
                    if (!type[v]) 
                        break;
                    if (!vis[v])
                        vis[v] = true;
                    if (type[v] == 1) 
                        v = -1;
                } else break;
            } else {
                para[v] = c;
                v = -1;
            }
            t++;
        }
        cout << "Case " << kase << ":";
        for (int i = 0; i < N; i++) //按字母升序输出
        {
            if (!vis[i]) continue;
            cout << " -" << (char) ('a' + i);
            if (type[i] == 2) cout << " " << para[i];
        }
        cout << endl;
    }
    return 0;
}
