//╣з╟куб╣з1лБ
#include <iostream>

using namespace std;

class Time {
	private:
		int hour;
		int minute;
		int sec;
	public:
		void set_time();
		void shouw_time();
};

void Time::set_time() {
	cin >> hour >> minute >> sec;
}

void Time::shouw_time() {
	cout << hour << ":" << minute << ":" << sec << endl;
}

int main() {
	Time t;
	t.set_time();
	t.shouw_time();
	return 0;
}
