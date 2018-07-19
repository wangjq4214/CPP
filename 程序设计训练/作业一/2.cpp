// 日历问题 
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

string dayOfWeek[] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
int year[] = {365,366};
int day[][12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int run(int);

int main() {
	int n;
	while (cin >> n && n != -1) {
		string dayWeek = dayOfWeek[n % 7];
		int YYYY = 2000, MM = 0, DD = 0;
		for (YYYY; n >= year[run(YYYY)]; ++YYYY) {
			n -= year[run(YYYY)];
		}
		for(MM; n >= day[run(YYYY)][MM]; MM++) {
			n -= day[run(YYYY)][MM];
		}
		MM++;
		DD = n + 1;
		cout << YYYY << '-'
		     << setw(2) << setfill('0') << MM << '-'
		     << setw(2) << setfill('0') << DD
		     << " " << dayWeek << endl;
	}
}

int run(int YYYY) {
	return ((YYYY % 4 == 0 && YYYY % 100 != 0) || YYYY % 400 == 0) ? 1 : 0;
}
