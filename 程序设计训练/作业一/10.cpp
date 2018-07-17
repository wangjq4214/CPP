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
	for (int i = 0; i < str1.length(); ++i) {
		bought[str1[i]] += 1;
	}
	for (int i = 0; i < str2.length(); ++i) {
		buying[str2[i]] += 1;
	}
	
	map<char, int> temp;
	
	for (map<char, int>::iterator iter = bought.begin(); iter != bought.end(); ++iter) {
		temp[iter->first] = iter->second - buying[iter->first];
	}
	for (map<char, int>::iterator iter = buying.begin(); iter != buying.end(); ++iter) {
		temp[iter->first] = -(iter->second - bought[iter->first]);
	}
	
	int sum1 = 0, sum2 = 0;
	for (map<char, int>::iterator iter = temp.begin(); iter != temp.end(); ++iter) {
		if (iter->second >= 0) {
			sum1 += iter->second;
		} else {
			sum2 += iter->second;
		}
	}
	
	if (sum2 < 0) {
		cout << "No" << " " << -sum2;
	} else {
		cout << "Yes" << " " << sum1;
	}
}
