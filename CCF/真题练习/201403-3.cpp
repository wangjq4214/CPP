#include<iostream>
#include <cstring>

using namespace std;
const int N = 26;
int type[N]; //0�������ڣ�1����������ѡ�2���������ѡ��
bool vis[N]; //���ʱ��
string para[N]; //����
int main() {
    int n;
    string order, c;
    cin >> order;
    int l = order.length();
    memset(type, 0, sizeof(type));
    //����ѡ������
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
        int v = -1; //-1�����������Ӧ����ѡ����������������Ӧ���ǲ���
        int t = 0;
        l = order.length();
        while (order[t] != ' ' && t < l) {
            t++;
        } //��ȥls
        t++;
        for (; t < l;) {
            c = "";
            while (order[t] != ' ' && t < l) {
                c += order[t++];
            }
            if (v == -1) //���벢�ж�ѡ��
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
        for (int i = 0; i < N; i++) //����ĸ�������
        {
            if (!vis[i]) continue;
            cout << " -" << (char) ('a' + i);
            if (type[i] == 2) cout << " " << para[i];
        }
        cout << endl;
    }
    return 0;
}
