//╣з╟куб╣з6лБ
#include <iostream>

using namespace std;

class chang {
	private:
		double length;
		double width;
		double height;
	public:
		void set();
		void doandshow();
};

void chang::set() {
	cin >> length >> width >> height;
}

void chang::doandshow() {
	cout << length * width * height;
}

int main() {
	chang ch1;
	ch1.set();
	ch1.doandshow();
	return 0;
}
