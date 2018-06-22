//สตั้ถþ
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Birthday {
		int year;
		int month;
		int day;
	public:
		void setBirthday();
		void Birthdayshow() {
			cout << "Birthday:" << year << "/" << month << "/" << day << endl;
		}
};

void Birthday::setBirthday() {
	int yea, mont, da;
	cin >> yea >> mont >> da;
	year = yea;
	month = mont;
	day = da;
}

class People {
	private:
		string number;
		string name;
		string sex;
		Birthday birthday;
		string id;
		int years;
		int *averagesalar;
	private:
		void Free();
	public:
		void setPeople();
		People operator=(const People&);
		bool operator==(const People&);
		void Popleshow();
		~People();
};

void People::Free() {
	delete [] averagesalar;
}

void People::setPeople() {
	cin >> number;
	cin >> name;
	cin >> sex;
	birthday.setBirthday();
	cin >> id;
	cin >> years;
	averagesalar = new int [years];
	for (int i = 0; i < years; i++) {
		cin >> *(averagesalar + i);
	}
}

People People::operator=(const People &peo) {
	number = peo.number;
	name = peo.name;
	sex = peo.sex;
	birthday = peo.birthday;
	id = peo.id;
	years = peo.years;
	averagesalar = new int [years];
	memcpy(averagesalar, peo.averagesalar, sizeof(peo.averagesalar));
}

bool People::operator==(const People &peo) {
	if (id == peo.id) {
		return true;
	} else {
		return false;
	}
}

void People::Popleshow() {
	cout << "Number:" << number << endl;
	cout << "Name:" << name << endl;
	cout << "Sex:" << sex << endl;
	birthday.Birthdayshow();
	cout << "ID:" << id << endl;
	cout << "Years:" << years << endl;
	cout << "Average:";
	for (int i = 0; i < years; i++) {
		cout << *(averagesalar + i) << " ";
	}
}

People::~People() {
	Free();
}

int main() {
	People peo1, peo2;
	cout << "Please input:" << endl;
	peo1.setPeople();
	peo2 = peo1;
	if (peo2 == peo1) {
		cout << "Same";
	} else {
		cout << "Different";
	}
	peo1.Popleshow();
	peo2.Popleshow();
	peo1.~People();
	peo2.~People();
}
