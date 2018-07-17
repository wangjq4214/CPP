//Êä³ön²ã½ğ×ÖËşÍ¼ĞÎ.cpp

#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	for (int i1 = 1; i1 <= n; i1++)
	{
		for (int i2 = 1; i2 <= (n -i1); i2 ++)
		{
			cout << " ";
		}
		for (int i3 =1; i3 <= (2 * i1 -1); i3 ++)
		{
			cout << "*";
		}
		
		cout << endl;
	}
	
	return 0;
}
