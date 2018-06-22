#include "people.h"

using std::cin;
using std::cout;
using std::endl;

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
		cin >> averagesalar[i];
	}
}

People& People::operator=(const People &peo) {
	this->number = peo.number;
	this->name = peo.name;
	this->sex = peo.sex;
	this->birthday = peo.birthday;
	this->id = peo.id;
	this->years = peo.years;
	this->averagesalar = new int [years];
	memcpy(averagesalar, peo.averagesalar, sizeof(peo.averagesalar));
	return *this;
}

bool People::operator==(const People &peo) {
	if (this->id == peo.id) {
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
		cout << averagesalar[i] << " ";
	}
	cout << endl;
}

People::~People() {
	Free();
}
