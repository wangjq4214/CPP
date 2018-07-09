#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

struct Essay {
	string title;
	string lowTitle;
	int quote;
	int num;
	vector<string> devide;
};

bool compare(const Essay &x, const Essay &y) {
	if (x.quote == y.quote) {
		return x.num < y.num;
	} else {
		return x.quote > y.quote;
	}
}

int main() {
	int n, m;
	while (cin >> n && n != 0) {
		Essay essay[n];
		// 读入数据
		for (int i = 0; i < n; ++i) {
			cin.get();
			getline(cin, essay[i].title);
			cin >> essay[i].quote;
			essay[i].num = i;
			essay[i].lowTitle = essay[i].title;
			// 小写转化
			transform(essay[i].title.begin(), essay[i].title.end(), essay[i].lowTitle.begin(), ::tolower);
			// 分词
			string str;
			for (int j = 0; j < essay[i].lowTitle.size(); ++j) {
				if (essay[i].lowTitle[j] == ' ') {
					essay[i].devide.push_back(str);
					str.clear();
				} else {
					str += essay[i].lowTitle[j];
				}
			}
			essay[i].devide.push_back(str);
		}

		// 排序
		sort(essay, essay + n, compare);

		cin >> m;
		string str;
		cin.get();
		for (int i = 0; i < m; ++i) {
			getline(cin, str);
			transform(str.begin(), str.end(), str.begin(), ::tolower);
			// 分词
			vector<string> temp;
			string str1;
			for (int j = 0; j < str.size(); ++j) {
				if (str[j] == ' ') {
					temp.push_back(str1);
					str1.clear();
				} else {
					str1 += str[j];
				}
			}
			temp.push_back(str1);

			// 匹配
			for (int j = 0; j < n; ++j) {
				bool judge = true;
				int l = 0;
				for (int k = 0; k < temp.size() && judge; ++k) {
					for (l; l < essay[j].devide.size(); ++l) {
						if (temp[k] == essay[j].devide[l]) {
							judge = true;
							break;
						} else {
							judge = false;
						}
					}
				}
				if (judge) {
					cout << essay[j].title << endl;
				}
			}
			cout << "***" << endl;
		}
		cout << "---" << endl;
	}
}
