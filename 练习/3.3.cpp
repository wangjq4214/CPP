//3.3
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	double huashi, c;
	
	cout << "请输入一个华氏温度：" << endl;
	cin >> huashi;
	c = (5.0/9.0) * (huashi - 32);
	cout << "摄氏温度："  << setiosflags(ios::fixed) << setprecision(2) << c;
	
	return 0; 
}
