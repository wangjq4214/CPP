#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

struct Goal {
	int goal;
	int realGoal;
	int num;
	Goal() {
		goal = 0;
		realGoal = 0;
		num = 0;
	}
};

bool comp(const pair<string, Goal> &x, const pair<string, Goal> &y) {
	if ((x.second).num == (y.second).num && (x.second).realGoal == (y.second).realGoal) {
		return (x.second).goal > (y.second).goal;
	} else if ((x.second).num == (y.second).num) {
		return (x.second).realGoal > (y.second).realGoal;
	} else {
		return (x.second).num > (y.second).num;
	}
}

int main() {
	int n;
	map<string, Goal> team;
	vector<pair<string, Goal> > team2;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		string str;
		cin >> str;
		team[str];
	}

	for (int i = 0; i < (n * (n - 1)) / 2; ++i) {
		string str1, str2;
		cin >> str1;
		cin >> str2;
		// 第一次分词
		vector<string> temp1, temp2;
		string str;
		for (int j = 0; j < str1.size(); ++j) {
			if (str1[j] == '-') {
				temp1.push_back(str);
				str.clear();
			} else {
				str += str1[j];
			}
		}
		temp1.push_back(str);
		// 第二次分词
		str.clear();
		for (int j = 0; j < str2.size(); ++j) {
			if (str2[j] == ':') {
				temp2.push_back(str);
				str.clear();
			} else {
				str += str2[j];
			}
		}
		temp2.push_back(str);
		int x, y;
		stringstream sstr;
		sstr << temp2[0];
		sstr >> x;
		sstr.clear();
		sstr << temp2[1];
		sstr >> y;
		if (x > y) {
			team[temp1[0]].num += 3;
		} else if (x < y) {
			team[temp1[1]].num += 3;
		} else {
			team[temp1[0]].num += 1;
			team[temp1[1]].num += 1;
		}
		team[temp1[0]].goal += x;
		team[temp1[1]].goal += y;
		team[temp1[0]].realGoal += (x - y);
		team[temp1[1]].realGoal += (y - x);
	}
	
	for (map<string, Goal>::iterator iter = team.begin(); iter != team.end(); ++iter) {
		team2.push_back(make_pair(iter->first, iter->second));
	}
	
	sort(team2.begin(), team2.end(), comp);
	
	vector<string> team3;
	for (int i = 0; i < n / 2; ++i) {
		team3.push_back(team2[i].first);
	}
	sort(team3.begin(), team3.end());
	for (int i = 0; i < n / 2; ++i) {
		cout << team3[i] << endl;
	}
}
