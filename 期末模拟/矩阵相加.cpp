#include <iostream>
using namespace std;
int n=0; //ȫ�ֱ���n��ʾ����Ľ���
class Matrix {
	private:
		int** data; //����ָ�룬ָ��̬����Ķ�ά����
	public:
		Matrix(); //�޲ι��캯��
		void operator+(Matrix&); //�Գ�Ա������ʽ���صļӷ������ �����ں����ڲ����������
		friend istream& operator>> (istream&,Matrix&); //����Ԫ������ʽ���ص����������
		~Matrix();//��������
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
