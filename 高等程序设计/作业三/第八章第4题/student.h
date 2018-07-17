#ifndef STUDENT_H
#define STUDENT_H
#include <string>

using std::string;

class student{
	private:
		int num;
		string name;
		char sex;
	public:
		void set_value();
		void display(); 
};

#endif
