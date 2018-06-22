//第十章第5题
#include <iostream>

using namespace std;

class Matrix {
	private:
		double matrix[2][3];
	public:
		friend istream& operator >>(istream&, Matrix&);
		Matrix& operator +(const Matrix&);
		friend ostream& operator <<(ostream&, Matrix&);
};

istream& operator >>(istream& input, Matrix& m) {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			input >> m.matrix[i][j];
		}
	}
	return input;
}

ostream& operator <<(ostream& output, Matrix&m) {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			output << m.matrix[i][j] << " ";
		}
		output << endl;
	}
	return output;
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
	cin >> m1;
	cin >> m2;
	m1 + m2;
	cout << m1;
}
