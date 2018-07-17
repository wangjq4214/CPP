//3.2

#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main()
{
	double bj, g;

	cout << "请依次输入半径与高：" << endl;
	cin >> bj;
	cin >> g;
	cout << "圆周长：" << setiosflags(ios::fixed) << setprecision(2) << 2 * bj * M_PI << endl;
	cout << "圆面积：" << setiosflags(ios::fixed) << setprecision(2) << bj * bj * M_PI << endl;
	cout << "圆球表面积：" << setiosflags(ios::fixed) << setprecision(2) << 4 * M_PI * bj * bj << endl;
	cout << "圆球体积：" << setiosflags(ios::fixed) << setprecision(2) << 4/3 * M_PI * bj * bj *bj <<endl;
	cout << "圆柱体积：" << setiosflags(ios::fixed) << setprecision(2) << g * bj * bj * M_PI << endl;
	
	return 0; 
}
