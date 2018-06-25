#include <iostream>
#include <map>

using namespace std;

int main() {
	map<int, int> duoXiangShi;
	int index;
	int retio;
	
	while (cin >> index >> retio && retio != 0) {
		int x = duoXiangShi[index];
		duoXiangShi[index] = retio + x;
	}
	while (cin >> index >> retio && retio != 0) {
		int x = duoXiangShi[index];
		duoXiangShi[index] = retio + x;
	}
	
	for (map<int, int>::reverse_iterator iter = duoXiangShi.rbegin(); iter != duoXiangShi.rend(); ++iter) {
		cout << iter->first << " " << iter->second << endl;
	}
}
