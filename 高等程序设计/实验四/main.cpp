#include <iostream>
#include <windows.h>
#include "science.h"
#include "project.h"

using namespace std;

void first() {
	cout << "===============�о�������ϵͳ===============" << endl << endl;
	cout << "=======������ѡ��ǰ���ֽ�����һ������=======" << endl << endl;
	cout << "===========1-------------ѧ��˶ʿ===========" << endl;
	cout << "============================================" << endl;
	cout << "===========2-------------����˶ʿ===========" << endl;
	cout << "============================================" << endl;
	cout << "===========0-------------�˳�ϵͳ===========" << endl;
}

void second() {
	cout << "===============�о�������ϵͳ===============" << endl << endl;
	cout << "=======������ѡ��ǰ���ֽ�����һ������=======" << endl << endl;
	cout << "===========1-------------�����Ա===========" << endl;
	cout << "============================================" << endl;
	cout << "===========2-------------ɾ����Ա===========" << endl;
	cout << "============================================" << endl;
	cout << "===========3---------�޸���Ա��Ϣ===========" << endl;
	cout << "============================================" << endl;
	cout << "===========4---------��ѯ��Ա��Ϣ===========" << endl;
	cout << "============================================" << endl;
	cout << "===========5-----���������Ա��Ϣ===========" << endl;
	cout << "============================================" << endl;
	cout << "===========6-------------����ܷ�===========" << endl;
	cout << "============================================" << endl;
	cout << "===========7-------------�������===========" << endl;
	cout << "============================================" << endl;
	cout << "===========8-----------���ƽ����===========" << endl;
	cout << "============================================" << endl;
	cout << "===========9---------����ֶ����===========" << endl;
	cout << "============================================" << endl;
	cout << "===========0-----------������һ��===========" << endl;
}

void running() {
	while (1) {
		system("cls");
		first();
		int n;
		cin >> n;
		if (n == 0) {
			break;
		}
		switch (n) {
			case 1:
				while (1) {
					system("cls");
					second();
					Science science;
					science.Filein();
					cin >> n;
					if (n == 0) {
						break;
					}
					switch (n) {
						case 1:
							system("cls");
							cin >> science;
							science.Fileout();
							system("pause");
							break;
						case 2:
							system("cls");
							science.clean();
							science.Fileout();
							system("pause");
							break;
						case 3:
							system("cls");
							science.revise();
							science.Fileout();
							system("pause");
							break;
						case 4:
							system("cls");
							science.find_it();
							science.Fileout();
							system("pause");
							break;
						case 5:
							system("cls");
							cout << science;
							science.Fileout();
							system("pause");
							break;
						case 6:
							system("cls");
							science.sum_sum();
							science.Fileout();
							system("pause");
							break;
						case 7:
							system("cls");
							science.sum_count2();
							science.Fileout();
							system("pause");
							break;
						case 8:
							system("cls");
							science.average();
							science.Fileout();
							system("pause");
							break;
						case 9:
							system("cls");
							science.census();
							science.Fileout();
							system("pause");
							break;
					}
				}
				break;
			case 2:
				while (1) {
					system("cls");
					second();
					Project project;
					project.Filein();
					cin >> n;
					if (n == 0) {
						break;
					}
					switch (n) {
						case 1:
							system("cls");
							cin >> project;
							project.Fileout();
							system("pause");
							break;
						case 2:
							system("cls");
							project.clean();
							project.Fileout();
							system("pause");
							break;
						case 3:
							system("cls");
							project.revise();
							project.Fileout();
							system("pause");
							break;
						case 4:
							system("cls");
							project.find_it();
							project.Fileout();
							system("pause");
							break;
						case 5:
							system("cls");
							cout << project;
							project.Fileout();
							system("pause");
							break;
						case 6:
							system("cls");
							project.sum_sum();
							project.Fileout();
							system("pause");
							break;
						case 7:
							system("cls");
							project.sum_count2();
							project.Fileout();
							system("pause");
							break;
						case 8:
							system("cls");
							project.average();
							project.Fileout();
							system("pause");
							break;
						case 9:
							system("cls");
							project.census();
							project.Fileout();
							system("pause");
							break;
					}
				}
				break;
		}
	}
}

int main() {
	running();
	return 0;
}

