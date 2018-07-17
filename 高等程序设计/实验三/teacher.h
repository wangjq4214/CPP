#ifndef TEACHER_H
#define TEACHER_H

#include "people.h"

class Teacher:virtual public People {
	protected:
		char principalship[11];
		char department[21];
	public:
		virtual void set();
		virtual void display();
};

#endif
