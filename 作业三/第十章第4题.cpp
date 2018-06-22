//第十章第4题
#include <iostream>

using namespace std;

class Matrix {
	private:
		double matrix[2][3];
	public:
		void set();
		Matrix& operator +(const Matrix&);
		void show();
};

void Matrix::set() {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> matrix[i][j];
		}
	}
}

void Matrix::show() {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

Matrix& Matrix::operator +(const Matrix &m) {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			this -> matrix[i][j] += m.matrix[i][j];
		}
	}
}

int main() {
	Matrix m1, m2;
	m1.set();
	m2.set();
	m1 + m2;
	m1.show();
}
