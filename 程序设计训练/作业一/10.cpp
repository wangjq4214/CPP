#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
	map<char, int> bought;
	map<char, int> buying;
	string str1, str2;
	cin >> str1;
	cin >> str2;
	for (int i = 0; i < str1.size(); ++i) {
		bought[str1[i]]++;
		buying[str1[i]];
	}
	
	for (int i = 0; i < str2.size(); ++i) {
		buying[str2[i]]++;
		bought[str2[i]];
	}
	
	int sum1 = 0, sum2 = 0;
	for (map<char, int>::iterator iter = bought.begin(); iter != bought.end(); ++iter) {
		int temp = iter->second - buying[iter->first];
		if (temp > 0) {
			sum1 += temp;
		} else {
			sum2 += temp;
		}
	}
	
	
	if (sum2 < 0) {
		cout << "No" << " " << -sum2;
	} else {
		cout << "Yes" << " " << sum1;
	}
}
