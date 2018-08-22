#include <bits/stdc++.h>

using namespace std;

struct Word {
    string str;
    int use;

    Word() {
        use = 0;
    }
};

int canLink(const string &, const string &);

void findIt(int, int &, Word *, const string &, int);

int main() {
    int n, length = 1;
    cin >> n;
    Word word[n + 1];
    for (int i = 0; i <= n; ++i) {
        cin >> word[i].str;
    }
    findIt(n, length, word, word[n].str, 1);
    cout << length;
}

int canLink(const string &str1, const string &str2) {
    for (int i = str1.size() - 1; i >= 0; --i) {
        string temp = str1.substr(i);
        if (str2.find(temp) == 0) {
            return str1.size() - i;
        }
    }

    return 0;
}

void findIt(int n, int &length, Word *word, const string &stringNow, int lengthNow) {
    length = max(length, lengthNow);
    for (int i = 0; i < n; ++i) {
        if (word[i].use == 2) {
            continue;
        }
        int link = canLink(stringNow, word[i].str);
        if (link > 0) {
            word[i].use++;
            findIt(n, length, word, word[i].str, lengthNow + word[i].str.size() - link);
            word[i].use--;
        }
    }
}
