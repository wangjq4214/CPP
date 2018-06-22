//**********intSLList.cpp**********

#include <iostream>
#include "intSLList.h"

IntSLList::~IntSLList() {
	for (IntSLLNode *p; !isEmpty(); ) {
		p = head->next;
		delete head;
		head = p;
	}
}

void IntSLList
