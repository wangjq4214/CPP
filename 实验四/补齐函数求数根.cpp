#include <iostream> 
#include <cmath> 

using namespace std; 

int root(int); 
int sum(int); 

int main() 
{ 
	int n; 
	cin >> n; 
	int num; 
	for (int i=1;i<=n;i++) 
	{ 
		cin >> num; 
		cout << root(num) << " "; 
	}
	return 0; 
} 

int root(int x)  
{
	if (sum(x) < 10)
	{
		return sum (x);
	}
	else
	{
		return sum(sum(x));
	}
}

int sum(int y) 
{ 
	int t=y,result=0; 
	while(t>0) 
	{ 
		result = result + t%10; 
		t = t / 10; 
	}
	return result; 
} 
