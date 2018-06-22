#include<iostream> 
#include<iomanip> 

using namespace std; 

float f1(int,int); 

int main() 
{ 
    int x, y; 
    cin >> x >> y; 
    cout << setiosflags(ios::fixed) << setprecision(2); 
    cout << f1(x, y) ; 
    return 0; 
} 

float f1(int x, int y)
{
	if (y == 0)
	{
		return 1;
	}
	else if (y > 0)
	{
		if (y == 1)
		{
			return x;
		}
		else
		{
			return f1(x, y - 1) * x;
		}
	}
	else
	{
		if (y == -1)
		{
			return (1.0/x);
		}
		else
		{
			return (f1(x, y + 1) * (1.0/x));
		}
	}
}
