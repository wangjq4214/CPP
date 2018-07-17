#ifndef PEOPLE_H
#define PEOPLE_H

#include <string>
#include "date.h"

using std::string;

class People {
	protected:
		string number;
		string name;
		char sex;
		Date birthday;
		string id;
	public:
		People();
		People(const People&);
		virtual void set();
		virtual void display();
		~People();
};

#endif
