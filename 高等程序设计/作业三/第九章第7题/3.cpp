//第九章第7题
#include <iostream>

using namespace std;

class Student {
	private:
		mutable int num;
		mutable float score;
	public:
		Student(int n, float s):num(n), score(s) {}
		void change(int n, float s) const {
			num = n;
			score = s;
		}
		void display() const {
			cout << num << " " << score << endl;
		}
};

int main() {
	const Student stud(101, 78.5);
	const Student *p = &stud;
	//Student *const p = &stud;
	//不可以 
	p -> change(101, 80.5);
	p -> display();
	return 0;
} 
