#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class animal {
	protected:
		string name;
		int length;
		int weight;
		char ch;
	public:
		animal(string na = "null", int le = 0, int we = 0, char c = 'n') {
			name = na;
			length = le;
			weight = we;
			ch = c;
		}
};

class ter_animal: virtual public animal {
	protected:
		int tspeed;
	public:
		ter_animal(string na = "null", int le = 0, int we = 0, char c = 'n', int ts = 0) {
			animal(na, le, we, c);
			tspeed = ts;
		}
};

class aqu_animal: virtual public animal {
	protected:
		int aspeed;
	public:
		aqu_animal(string na = "null", int le = 0, int we = 0, char c = 'n', int as = 0) {
			animal(na, le, we, c);
			aspeed = as;
		}
};

class amp_animal: virtual public ter_animal, virtual public aqu_animal {
	public:
		amp_animal(string na = "null", int le = 0, int we = 0, char c = 'n', int ts = 0, int as = 0) {
			ter_animal(na, le ,we ,c , ts);
			aqu_animal(na, le ,we ,c , as);
		}

		void input() {
			cin >> name >> length >> weight >> ch >> tspeed >> aspeed;
		}

		void display() {
			cout << "name:" << name << endl;
			cout << "height:" << length << endl;
			cout << "weight:" << weight << endl;
			cout << "sex:" << ch << endl;
			cout << "running_speed:" << tspeed << endl;
			cout << "swimming_speed:" << aspeed << endl;
		}

		int re() const {
			return aspeed;
		}
};

bool compare1(const amp_animal &a1, const amp_animal &a2) {
	return a1.re() > a2.re();
}

int main() {
	amp_animal amp[3];

	for (int i = 0; i < 3; i++) {
		amp[i].input();
	}

	sort(amp, amp + 3, compare1);

	for (int i = 0; i < 3; i++) {
		amp[i].display();
	}
}
