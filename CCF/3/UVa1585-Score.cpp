#include<bits/stdc++.h>//����ͷ�ļ� 

using namespace std;

int main() {
	int t;
	cin >> t;//������������
	while (t--) {
		string str;
		int s = 0,t = 0;//s��ʾ�����ĺ� t��ʾ��ǰ�������˼���
		cin >> str;
		for(int i = 0; i < str.size(); i++) {
			if(str[i]=='O') {
				t++;
				s += t;//�����ۺ�
			} else t=0; //��0
		}
		cout << s << endl;
	}
	return 0;
}
