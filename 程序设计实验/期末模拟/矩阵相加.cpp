#include <iostream>
using namespace std;
int n=0; //全局变量n表示矩阵的阶数
class Matrix {
	private:
		int** data; //二级指针，指向动态申请的二维数组
	public:
		Matrix(); //无参构造函数
		void operator+(Matrix&); //以成员函数形式重载的加法运算符 ，并在函数内部输出运算结果
		friend istream& operator>> (istream&,Matrix&); //以友元函数形式重载的输入运算符
		~Matrix();//析构函数
};
Matrix::Matrix() {
	data=NULL;
}

void Matrix::operator+(Matrix &m1) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			this->data[i][j] += m1.data[i][j];
			cout << this->data[i][j] << " ";
		}
		cout << endl;
	}
}

istream& operator >>(istream &input, Matrix &m) {
	m.data = new int* [n];
	for (int i = 0; i < n; i++) {
		m.data[i] = new int [n];
		for (int j = 0; j < n; j++) {
			input >> m.data[i][j];
		}
	}
}

Matrix::~Matrix() {
	for (int i = 0; i < n; i++) {
		delete []data[i];
	}
	
	delete []data;
}

int main() {
	Matrix m1,m2;
	cin >> n;
	cin >> m1;
	cin >> m2;
	m1 + m2;
	return 0;
}
