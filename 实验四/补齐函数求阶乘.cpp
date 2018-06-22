#include<iostream> 

using namespace std; 

long long f1(int n); 

int main() 
{ 
    int n = 0; 
    cin >> n; 
    long long sum = 0; 
    for(int i = 1;i <= n;i++) 
        sum = sum + f1(i); 
    cout << sum ; 

    return 0; 
} 

long long f1(int n) 
{ 
	long long sum = 1;
	for (int i = 1; i <= n; i++)
	{
		sum = sum * i;
	}
	
	return sum;
} 
