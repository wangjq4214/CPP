//µÚ¾ÅÕÂµÚ8Ìâ
#include <iostream>

using namespace std;

class Student {
	private:
		int num;
		float score;
	public:
		Student(int n, float s):num(n), score(s) {}
		void change(int n, float s) {
			num = n;
			score = s;
		}
		void display() {
			cout << num << " " << score << endl;
		}
};

void fun (Student&);

int main() {
	Student stud(101, 78.5);
	fun(stud);
	return 0;
}

void fun (Student &c) {
	c.display();
	c.change(101, 80.5);
	c.display();
}
