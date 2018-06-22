// πÈ≤¢≈≈–Ú
#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> linka;
	vector<int> linkb;
	vector<int> linkc;

	while (1) {
		int temp;
		cin >> temp;
		if (temp == 0) {
			break;
		}
		linka.push_back(temp);
	}

	while (1) {
		int temp;
		cin >> temp;
		if (temp == 0) {
			break;
		}
		linkb.push_back(temp);
	}

	while (!linka.empty() && !linkb.empty()) {
		if (linka[0] < linkb[0]) {
			linkc.push_back(linka[0]);
			vector<int>::iterator first = linka.begin();
			linka.erase(first);
		} else {
			linkc.push_back(linkb[0]);
			vector<int>::iterator first = linkb.begin();
			linka.erase(first);
		}
	}

	if (linka.empty()) {
		while (!linkb.empty()) {
			linkc.push_back(linkb[0]);
			vector<int>::iterator first = linkb.begin();
			linka.erase(first);
		}
	} else {
		while (!linka.empty()) {
			linkc.push_back(linka[0]);
			vector<int>::iterator first = linka.begin();
			linka.erase(first);
		}
	}
	
	for (int i = 0; i < linkc.size(); i++) {
		cout << linkc[i] << " ";
	}
	
	return 0;
}
