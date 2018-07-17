#include <iostream> 
#include <cmath> 

using namespace std; 

int main() 
{
	void godbaha(int); 
	int n; 
	cin>>n; 
	godbaha(n); 
	return 0; 
} 

void godbaha(int n)  
{
	int prime(int);
	for (int i = 2; i < (n/2); i++)
	{
		int a = n - i;
		if (prime(a) && prime(i))
		{
			cout << n << '=' << i << '+' << a << endl;
		}
	}
} 

int prime(int m) 
{
	int js = 0;
	for (int i = 2; i < (m/2); i++)
	{
		if (m % i == 0)
		{
			js++;
			break;
		}
	}
	if (js > 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
} 
