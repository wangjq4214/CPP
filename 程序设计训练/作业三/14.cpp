#include <iostream>
#include <map>
#include <cstring>
//#include <vector>

using namespace std;

int Rank[] = {25, 18, 15, 12, 10, 8, 6, 4, 2, 1};

struct Record {
    int grade;
    int ranging[100];

    Record() {
        grade = 0;
        memset(ranging, 0, sizeof(ranging));
    }
};

//bool comp1(const pair<string, Record> &x, const pair<string, Record> &y) {
//	if (x.second.grade == y.second.grade) {
//		for (int i = 0; i < 100; ++i) {
//			if (x.second.grade != y.second.grade)
//				return x.second.ranging[i] > y.second.ranging[i];
//		}
//	} else {
//		return x.second.grade > y.second.grade;
//	}
//}
//
//bool comp2(const pair<string, Record> &x, const pair<string, Record> &y) {
//	if (x.second.ranging[0] == y.second.ranging[0]) {
//		if (x.second.grade == y.second.grade) {
//			for (int i = 1; i < 100; ++i) {
//				if (x.second.grade != y.second.grade)
//					return x.second.ranging[i] > y.second.ranging[i];
//			}
//		} else {
//			return x.second.grade > y.second.grade;
//		}
//	} else {
//		return x.second.ranging[0] > y.second.ranging[0];
//	}
//}

int main() {
    int t, n;
    cin >> t;
    map<string, Record> record;
//	vector<pair<string, Record> > record1;

    for (int i = 0; i < t; ++i) {
        cin >> n;
        cin.get();
        for (int j = 0; j < n; ++j) {
            string str;
            getline(cin, str);
            record[str].grade += Rank[j];
            record[str].ranging[j]++;
        }
    }

    map<string, Record>::iterator max;
    max = record.begin();
    for (map<string, Record>::iterator iter = ++record.begin(); iter != record.end(); ++iter) {
        if (max->second.grade < iter->second.grade) {
            max = iter;
        } else if (max->second.grade > iter->second.grade) {
            continue;
        } else {
            for (int i = 0; i < 100; ++i) {
                if (max->second.ranging[i] < iter->second.ranging[i]) {
                    max = iter;
                } else if (max->second.ranging[i] > iter->second.ranging[i]) {
                    break;
                } else {
                    continue;
                }
            }
        }
    }
    cout << max->first << endl;

    max = record.begin();
    for (map<string, Record>::iterator iter = ++record.begin(); iter != record.end(); ++iter) {
        if (max->second.ranging[0] < iter->second.ranging[0]) {
            max = iter;
        } else if (max->second.ranging[0] > iter->second.ranging[0]) {
            continue;
        } else {
            if (max->second.grade < iter->second.grade) {
                max = iter;
            } else if (max->second.grade > iter->second.grade) {
                continue;
            } else {
                for (int i = 1; i < 100; ++i) {
                    if (max->second.ranging[i] < iter->second.ranging[i]) {
                        max = iter;
                    } else if (max->second.ranging[i] > iter->second.ranging[i]) {
                        break;
                    } else {
                        continue;
                    }
                }
            }
        }
    }

    cout << max->first << endl;

//	for (map<string, Record>::iterator iter = record.begin(); iter != record.end(); ++iter) {
//		record1.push_back(make_pair(iter->first, iter->second));
//	}
//
//	sort(record1.begin(), record1.end(), comp1);
//	cout << record1[0].first << endl;
//	sort(record1.begin(), record1.end(), comp2);
//	cout << record1[0].first << endl;
}
