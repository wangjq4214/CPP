#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {
	int n;
	cin >> n;
	int ranking[n];
	memset(ranking, 0, sizeof(ranking));
	vector<int> score;
	
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		score.push_back(x);
	}
	
	vector<int>::iterator temp = max_element(score.begin(), score.end());
	int temp1 = *temp;
	score[distance(score.begin(), temp)] = -1;
	
	while (count(score.begin(), score.end(), -1) != n) {
		if (*max_element(score.begin(), score.end()) == temp1) {
			temp = max_element(score.begin(), score.end());
			score[distance(score.begin(), temp)] = -1;
		} else {
			for (int i = 0; i < n; ++i) {
				if (score[i] != -1) {
					ranking[i]++;
				}
			}
			temp = max_element(score.begin(), score.end());
			temp1 = *temp;
			score[distance(score.begin(), temp)] = -1;
		}
	}
	
	for (int i = 0; i < n; ++i) {
		cout << ranking[i] + 1 << " ";
	}
}
