#include <iostream>
#include "people.h"

using std::cout;
using std::endl;

int main() {
	People peo1, peo2;
	cout << "Please input:" << endl;
	peo1.setPeople();
	peo2 = peo1;
	if (peo2 == peo1) {
		cout << "Same" << endl;
	} else {
		cout << "Different" << endl;
	}
	peo1.Popleshow();
	peo2.Popleshow();
	return 0;
}
