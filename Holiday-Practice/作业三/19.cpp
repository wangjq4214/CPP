#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
	int n;
	while (cin >> n && n != 0) {
		map<string, int> record;
		for (int i = 0; i < 2 * n - 1; ++i) {
			string str;
			str.resize(200);
			scanf("%s", &str[0]);
			record[str]++;
		}

		for (map<string, int>::iterator iter = record.begin(); iter != record.end(); ++iter) {
			if(iter->second == 1) {
				cout << iter->first << endl;
				break;
			}
		}
	}
}
