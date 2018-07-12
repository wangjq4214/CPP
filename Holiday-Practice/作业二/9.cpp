#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n, total = 0;
    cin >> n;
    double GPA = 0.0;
    int xf[n];
    double grade;
    for (int i = 0; i < n; i++) {
        cin >> xf[i];
        total += xf[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> grade;
        if (grade >= 90)
            GPA += xf[i] * 4.0;
        else if (grade >= 85 && grade <= 89)
            GPA += xf[i] * 3.7;
        else if (grade >= 82 && grade <= 84)
            GPA += xf[i] * 3.3;
        else if (grade >= 78 && grade <= 81)
            GPA += xf[i] * 3.0;
        else if (grade >= 75 && grade <= 77)
            GPA += xf[i] * 2.7;
        else if (grade >= 72 && grade <= 74)
            GPA += xf[i] * 2.3;
        else if (grade >= 68 && grade <= 71)
            GPA += xf[i] * 2.0;
        else if (grade >= 64 && grade <= 67)
            GPA += xf[i] * 1.5;
        else if (grade >= 60 && grade <= 63)
            GPA += xf[i] * 1.0;
        else
            GPA += xf[i] * 0.0;
    }
    double result = (GPA / total) * 1.0;
    cout << setprecision(2) << fixed << result;
    return 0;
}
