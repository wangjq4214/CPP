#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;
const int N = 1000 + 10;
int a[N], n;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	int ans = 0;
	for (int i = 1; i < n; i++)
		if (a[i] - a[i - 1] == 1) ans++;
	printf("%d\n", ans);
	return 0;
}
