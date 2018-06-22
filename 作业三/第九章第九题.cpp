//µÚ¾ÅÕÂµÚ9Ìâ
#include <iostream>
#include <string>

using namespace std;

class sale {
	private:
		static double discount;
		static double sum;
		static int n;
		string num;
		int quantity;
		double price;
	public:
		sale(string a, int b, double c):num(a), quantity(b), price(c) {}
		
		void tosum() {
			sum += price * quantity;
			n += quantity;
		}
		
		static double average() {
			return sum / n; 
		}
		
		static void display() {
			cout << sum << endl << average(); 
		}
};

double sale::discount = 0.98;
double sale::sum = 0;
int sale::n = 0;

int main() {
	sale s[3] = {sale("101", 5, 23.5), sale("102", 12, 24.56), sale("103", 100, 21.5)};
	for (int i = 0; i < 3; i++) {
		s[i].tosum();
	}
	sale::display();
}
