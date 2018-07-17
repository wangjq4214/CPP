#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main() {
	int n, a, b, c;
	while (cin >> n >> a >> b >> c) {
		// 处理读入的数据
		int grid[n];
		// 只能初始化为0或-1
		memset(grid, -1, sizeof(grid));
		string str;
		for (int i = 0; i < n; ++i) {
			cin >> str;
			if (str[0] == 'G') {
				int sum = 0;
				for (int j = 1; j < str.size(); ++j) {
					sum = sum * 10 + str[j] - '0';
				}
				grid[i] = sum;
			}
		}

		// 定义骰子
		int fx = c;

		int lele = 0, yueyue = 0;
		while (1) {
			fx = (a * fx + b) % 6 + 1;
			lele = (lele + fx > n - 1 ? 2 * (n - 1) - fx - lele : lele + fx);
			int count = 0;
			while (grid[lele] != -1) {
				if (count > n) {
					break;
				}
				lele = grid[lele];
				count++;
			}
			if (lele == n - 1) {
				cout << "Lele" << endl;
				break;
			}
			if (lele == yueyue) {
				yueyue = 0;
			}
			if (count > n) {
				cout << "Impossible" << endl;
				break;
			}
			fx = (a * fx + b) % 6 + 1;
			yueyue = (yueyue + fx > n - 1 ? 2 * (n - 1) - fx - yueyue : yueyue + fx);
			count = 0;
			while (grid[yueyue] != -1) {
				if (count > n) {
					break;
				}
				yueyue = grid[yueyue];
				count++;
			}
			if (yueyue == n - 1) {
				cout << "Yueyue" << endl;
				break;
			}
			if (lele == yueyue) {
				lele = 0;
			}
			if (count > n) {
				cout << "Impossible" << endl;
				break;
			}
		}
	}
}
