#include "birthday.h"

using std::cin;
using std::cout;
using std::endl;

void Birthday::setBirthday() {
	cin >> year >> month >> day;
}

void Birthday::Birthdayshow() {
	cout << "Birthday:" << year << "/" << month << "/" << day << endl;
}
