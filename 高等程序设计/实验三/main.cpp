#include <iostream>
#include "partgraduate.h"

using namespace std;

int main() {
	People peo1;
	peo1.display();
	peo1.set();
	People peo2(peo1);
	peo2.display();
	
	Partgraduate par;
	par.set();
	par.display();
}
