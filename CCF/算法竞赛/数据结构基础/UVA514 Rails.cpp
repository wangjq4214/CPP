#include<cstdio>
#include<stack>

using namespace std;
const int MAXN = 1010;
int train[MAXN];

int main() {
    int n, A, B, ok;
    while (scanf("%d", &n), n) {
        stack<int> s;
        while (scanf("%d", &train[1]), train[1]) {
            for (int i = 2; i <= n; i++) {
                scanf("%d", &train[i]);
            }
            A = B = ok = 1;
            while (B <= n) {
                if (A == train[B]) {
                    A++;
                    B++;
                } else if (!s.empty() && s.top() == train[B]) {
                    s.pop();
                    B++;
                } else if (A <= n) {
                    s.push(A++);
                } else {
                    ok = 0;
                    break;
                }
            }
            printf("%s\n", ok ? "Yes" : "No");
        }
        printf("\n");
    }
}
