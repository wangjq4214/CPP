//µÚ¾ÅÕÂµÚ4Ìâ
#include <iostream>
#include <string>

using namespace std;

class student {
	private:
		string num;
		int garde;
	public:
		void set();
		void show();
};

void student::set() {
	cin >> num >> garde;
}

void student::show() {
	cout << "num:" << num << endl;
	cout << "garde:" << garde << endl;
}

int main() {
	student *stu = new student[5];
	for (int i = 0; i < 5; i++) {
		(stu + i) -> set();
	}
	for (int i = 0; i < 5; i += 2) {
		(stu + i) -> show();
	}
}
