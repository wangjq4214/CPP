#include <iostream>
#include <algorithm>
#include <regex>

using namespace std;

struct Essay {
    string title;
    string lowTitle;
    int quote;
    int num;
};

bool compare(const Essay &x, const Essay &y) {
    if (x.quote == y.quote) {
        return x.num < y.num;
    } else {
        return x.quote > y.quote;
    }
}

int main() {
    int n, m;
    while (cin >> n && n != 0) {
        Essay essay[n];
        // ��������
        for (int i = 0; i < n; ++i) {
            cin.get();
            getline(cin, essay[i].title);
            cin >> essay[i].quote;
            essay[i].num = i;
            essay[i].lowTitle = essay[i].title;
            // Сдת��
            transform(essay[i].title.begin(), essay[i].title.end(), essay[i].lowTitle.begin(), ::tolower);
        }

        // ����
        sort(essay, essay + n, compare);

        cin >> m;
        string str;
        cin.get();
        for (int i = 0; i < m; ++i) {
            getline(cin, str);
            transform(str.begin(), str.end(), str.begin(), ::tolower);
            regex r1("^[a-z,\\s]* " + str + " [a-z,\\s]*$");
            regex r2("^[a-z,\\s]* " + str + " [a-z,\\s]*$");
            // ƥ��
            for (int j = 0; j < n; ++j) {
                if (regex_match(essay[j].lowTitle, r1) || regex_match(essay[j].lowTitle, r2)) {
                    cout << essay[j].title << endl;
                }
            }
            cout << "***" << endl;
        }
        cout << "---" << endl;
    }
}
