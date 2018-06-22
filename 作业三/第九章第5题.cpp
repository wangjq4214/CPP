//µÚ¾ÅÕÂµÚ5Ìâ
#include <iostream>
#include <string>

using namespace std;

class student {
	private:
		string num;
		int garde;
	public:
		void set();
		int regarde() {
			return garde;
		}
		string renum() {
			return num;
		}
};

void student::set() {
	cin >> num >> garde;
}


void max(student*);

int main() {
	student *stu = new student[5];
	for (int i = 0; i < 5; i++) {
		(stu + i) -> set();
	}
	
	max(stu);
}

void max(student *stu) {
	int j = 0;
	int max1 = stu -> regarde();
	for (int i = 1; i < 5; i++) {
		if (((stu + i) -> regarde()) > max1) {
			max1 = (stu + i) -> regarde();
			j = i; 
		}
	}
	
	cout << (stu + j) -> renum();
}
