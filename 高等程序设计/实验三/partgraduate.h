#ifndef PARTGRADUATE_H
#define PARTGRADUATE_H

#include "student.h"
#include "teacher.h"

class Partgraduate:virtual public Student, virtual public Teacher {
	private:
		char subject[21];
		Teacher adviser;
	public:
		virtual void set();
		virtual void display();
};

#endif
