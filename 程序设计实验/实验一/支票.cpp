//输入支票代码（正整数）和支票金额（浮点数）；按格式要求输出：支票代码占8位，不足8位，则补充前导符‘0’；支票金额以￥开始，并保留两位小数 。

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int zpdm;
	double zpje;
	
	cin >> zpdm >> zpje;
	
	cout << setfill('0') << setw(8) << zpdm << endl;
	cout << setiosflags(ios::fixed) << setprecision(2) << zpje << endl;
	
	return 0;
}
