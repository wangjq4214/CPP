//第十章第7题
#include <iostream>
#include <string>

using namespace std;

class Teacher {
	private:
		int num;
		string name;
		char sex;
	public:
		Teacher(int n, string na, char s):num(n), name(na), sex(s) {}
		void show() {
			cout << num << endl;
			cout << name << endl;
			cout << sex << endl;
		}
};

class Student {
	private:
		int num;
		string name;
		char sex;
	public:
		Student(int n, string na, char s):num(n), name(na), sex(s) {}
		operator Teacher() {
			return Teacher(num, name, sex);
		}
};

int main() {
	Student s1(2017, "WANG", 'M');
	Teacher t1 = (Teacher) s1;
	t1.show();
}
