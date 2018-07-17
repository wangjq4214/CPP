#ifndef STUDENT_H
#define STUDENT_H

#include "people.h"

class Student:virtual public People {
	protected:
		char classNO[7];
	public:
		virtual void set();
		virtual void display();
};

#endif 
