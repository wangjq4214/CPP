#include <iostream>
#include <stack>

using namespace std;

int main() {
    string str;
    while (cin >> str) {
        stack<char> total;
        for (int i = 0; i < str.size(); ++i) {
            if (str[i] == '(') {
                total.push(str[i]);
            } else if (str[i] == ')' && total.top() == '(') {
                total.pop();
            } else if (str[i] == 'B') {
                break;
            }
        }
        int count = 0;
        while (!total.empty()) {
            total.pop();
            count++;
        }

        cout << count << endl;
    }
}
