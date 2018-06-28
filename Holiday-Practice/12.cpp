#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string re[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

int main() {
	string str;
	cin >> str;
	int sum = 0;
	for (int i = 0; i < str.length(); ++i) {
		sum += (str[i] - '0');
	}
	
	stringstream stream;
	stream << sum;
	stream >> str;
	for (int i = 0; i < str.length(); ++i) {
		cout << re[str[i] - '0'] << " ";
	}
}
