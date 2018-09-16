#include <bits/stdc++.h>

using namespace std;

int month[][12] = {{31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 356},
                   {31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366}};
int year[] = {365,
              366};
int week[] = {2, 3, 4, 5, 6, 7, 1};

int leap(int);

int main() {
    int a, b, c, y1, y2;
    cin >> a >> b >> c >> y1 >> y2;
    int sumDay = 0;
    for (int i = 1850; i <= y2; ++i) {
        int x = leap(i);
        if (i >= y1) {
            bool flag = false;
            int sum = sumDay + month[x][a - 2], count = 0;
            int dayOfWeek = week[sum % 7];
            for (int j = 0; j < month[x][a - 1] - month[x][a - 2]; ++j) {
                if (dayOfWeek > 7) {
                    dayOfWeek -= 7;
                }
                if (dayOfWeek == c) {
                    count++;
                    if (count == b) {
                        flag = true;
                        cout << i << "/" << setw(2) << setfill('0') << a << "/" << setw(2) << setfill('0') << j + 1
                             << endl;
                    }
                }
                dayOfWeek++;
            }
            if (!flag) {
                cout << "none" << endl;
            }
        }
        sumDay += year[x];
    }
}

int leap(int yyyy) {
    if ((yyyy % 4 == 0 && yyyy % 100 != 0) || yyyy % 400 == 0) {
        return 1;
    } else {
        return 0;
    }
}
