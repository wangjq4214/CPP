#include <iostream>
#include <string>
#include <cctype>

using namespace std;

char code[] = {'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U'};

int main() {
	string word;
	while (getline(cin, word)) {
		//cin.get();
		if (word == "ENDOFINPUT") {
			break;
		} else if (word == "START" || word == "END") {
			continue;
		} else {
			for (int i = 0; i < word.length(); ++i) {
				if (isupper(word[i])) {
					cout << code[word[i] - 'A'];
				} else {
					cout << word[i];
				}
			}
			cout << endl;
		}
	}
} 
