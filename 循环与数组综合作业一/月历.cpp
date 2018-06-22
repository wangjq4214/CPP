//ÔÂÀú
#include <iostream>
#include <iomanip>

using namespace std;

bool run(int);
int jisuan1(int);
int pdts(int, int);
int jisuan2(int, int);

int main(){
	int year, month, js, day;
	cin >> year >> month;
	
	day = jisuan1(year) + jisuan2(year, month);
	cout << "Sun Mon Tus Wed Thu Fri Sat\n";
	day % 7 == 0 ? js = 1 : js = day % 7 + 1;
	for (int i = 0; i < js; i++) {
		cout << setw(3) << "" << " ";
	}
	js++;
	for (int i = 1; i <= pdts(year,month); i++) {
		if (js == 7) {
			cout << setw(3) << i << endl;
			js = 1;
		} else {
			cout << setw(3) << i << " ";
			js++;
		}
	}
}

bool run(int year) {
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
		return true;
	} else {
		return false;
	}
}

int jisuan1(int year) {
	int sum = 0;
	for (int i = 1900; i < year; i++) {
		if (run(i)) {
			sum += 366;
		} else {
			sum += 365;
		}
	}
	return sum;
}

int pdts(int year, int month) {
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
		return 31;
	} else if (month == 4 || month == 6 || month == 9 || month == 11) {
		return 30;
	} else {
		if (run(year)) {
			return 29;
		} else {
			return 28;
		}
	}
}

int jisuan2(int year,int month) {
	int sum = 0;
	for (int i = 1; i < month; i++) {
		sum += pdts(year, i);
	}
	return sum;
}
