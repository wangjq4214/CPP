#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x = 0, y = 0;
        string str1, str2;
        cin >> str1 >> str2;
        int z = str1.size();
        for (int j = 0; j < str1.size(); ++j) {
            double xt = pow(26, --z);
            x += (str1[j] - 'a') * xt;
        }
        z = str2.size();
        for (int j = 0; j < str2.size(); ++j) {
            double xt = pow(26, --z);
            y += (str2[j] - 'a') * xt;
        }
        z = x + y;
        string temp;
        while (z) {
            string str = "a";
            str[0] = char(z % 26 + 'a');
            temp.insert(0, str);
            z /= 26;
        }
        cout << temp << endl;
    }
}
