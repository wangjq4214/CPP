//Ğ¡°à¿ÎÌÖÂÛ

#include <iostream>

using namespace std;

int main()
{
	int cs;
	cin >> cs;
	
	int a[cs + 1];
	for (int i = 1; i < cs + 1; i++)
	{
		cin >> a[i];
	}
	
	cin >> a[0]; 
	for (int i = 0; i < cs; i++)
	{
		if (a[i] > a[i + 1])
		{
			int t;
			t = a[i + 1];
			a[i + 1] = a[i];
			a[i] = t;
		}
	}
	
	cout << cs + 1 << endl;
	
	for (int i = 0; i < cs +1; i++)
	{
		cout << a[i] << " ";
	}
}
