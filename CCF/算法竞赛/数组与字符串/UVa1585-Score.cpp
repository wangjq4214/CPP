#include<bits/stdc++.h>//万能头文件 

using namespace std;

int main() {
	int t;
	cin >> t;//测试数据组数
	while (t--) {
		string str;
		int s = 0,t = 0;//s表示分数的和 t表示当前这道题得了几分
		cin >> str;
		for(int i = 0; i < str.size(); i++) {
			if(str[i]=='O') {
				t++;
				s += t;//分数累和
			} else t=0; //清0
		}
		cout << s << endl;
	}
	return 0;
}
