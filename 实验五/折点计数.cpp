//ÕÛµã¼ÆÊý

#include <iostream>

using namespace std;

int main()
{
	int num;
	cin >> num;
	int xsl[num];
	int zd = 0;
	
	for (int i = 0; i < num; i++)
	{
		cin >> xsl[i];
	}
	
	for (int i = 0; i < (num - 2); i++)
	{
		if (((xsl[i] - xsl[i + 1] ) > 0 && (xsl[i +1] - xsl[i + 2] ) < 0) || ((xsl[i] - xsl[i + 1] ) < 0 && (xsl[i +1] - xsl[i + 2] ) > 0))
		{
			zd++;
		}
	}
	
	cout << zd;
	
	return 0;
} 
