#include <iostream>

using namespace std;

string haab[] = {".pop", ".no", ".zip", ".zotz", ".tzec", ".xul", ".yoxkin", ".mol", ".chen", ".yax", ".zac", ".ceh",
                 ".mac",
                 ".kankin", ".muan", ".pax", ".koyab", ".cumhu", ".uayet"};
string toz[] = {"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben",
                "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int day, month, year;
        string temp;
        cin >> day >> temp >> year;
        for (int j = 0; j < 19; ++j) {
            if (temp == haab[j]) {
                month = j;
            }
        }
        int sum = year * 365 + month * 20 + day;
        int Tnumber, TnameOfTheDay, Tyear;
        Tyear = sum / 260;
        sum %= 260;
        Tnumber = (sum % 13) + 1;
        TnameOfTheDay = sum % 20;
        cout << Tnumber << " " << toz[TnameOfTheDay] << " " << Tyear << endl;
    }
}
