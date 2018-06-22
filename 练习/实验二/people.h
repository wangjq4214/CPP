#ifndef PEOPLE_H
#define PEOPLE_H

#include <string>
#include "birthday.h"
#include <iostream>

using std::string;

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
		People& operator=(const People&);
		bool operator==(const People&);
		void Popleshow();
		~People();
};

#endif
