#include <iostream>
#include <cstring>

using namespace std;

int main() {
	int duoXiangShi[1000];
	memset(duoXiangShi, 0, sizeof(duoXiangShi));
	int index;
	int retio;
	while (cin >> index >> retio && retio != 0) {
		duoXiangShi[index] += retio;
	}
	while (cin >> index >> retio && retio != 0) {
		duoXiangShi[index] += retio;
	}
	
	for (int i = 999; i >= 0; --i) {
		if (duoXiangShi[i] != 0) {
			cout << i << " " << duoXiangShi[i] << endl;
		}
	}
}
