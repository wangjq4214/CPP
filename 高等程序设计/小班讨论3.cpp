//±È½Ï×Ö·û´®
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n; 
	string str[n];
	string temp;
	for (int i = 0; i < n; i++)
	{
		cin >> str[i];
	}
	
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i; j < n - 1; j++)
		{
			if (str[i] > str[j + 1])
			{
				temp = str[i];
				str[i] = str[j + 1];
				str[j + 1] = temp;
			}
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		cout << str[i] << endl; 
	}
	
}
