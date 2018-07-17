//输入3组坐标，按指定格式输出

#include <iostream>

using namespace std;

int main()
{
	char z;
	int x1, x2, x3, y1, y2, y3;
	
	cin >> z >> x1 >> z >> y1 >> z >> z >> z >> x2 >> z >> y2 >> z >> z >> z >> x3 >> z >> y3 >>z;
	
	cout << '[' << x1 << ',' << y1 <<']' << endl;
	cout << '[' << x2 << ',' << y2 <<']' << endl;
	cout << '[' << x3 << ',' << y3 <<']' << endl;
	
	return 0;
 } 
