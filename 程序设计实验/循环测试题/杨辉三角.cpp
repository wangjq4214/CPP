//Со»ФИэЅЗ
#include <iostream>
#include <iomanip>

using namespace std; 

int jc(int);
int zh(int, int);

int main(){
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j <= i; j++){
			cout << left << setw(4) << zh(i, j);
		}
		cout << endl;
	}
	
	return 0;
}

int zh(int x, int y){
	int a = jc(x);
	int b = jc(y);
	int c = jc(x - y);
	return a / (b * c);
}

int jc(int x){
	int sum = 1;
	for (int i = 1; i <= x; i++){
		sum *= i;
	}
	return sum;
}
