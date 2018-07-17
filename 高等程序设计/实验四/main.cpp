#include <iostream>
#include <windows.h>
#include "science.h"
#include "project.h"

using namespace std;

void first() {
	cout << "===============研究生管理系统===============" << endl << endl;
	cout << "=======请输入选项前数字进行下一步操作=======" << endl << endl;
	cout << "===========1-------------学术硕士===========" << endl;
	cout << "============================================" << endl;
	cout << "===========2-------------工程硕士===========" << endl;
	cout << "============================================" << endl;
	cout << "===========0-------------退出系统===========" << endl;
}

void second() {
	cout << "===============研究生管理系统===============" << endl << endl;
	cout << "=======请输入选项前数字进行下一步操作=======" << endl << endl;
	cout << "===========1-------------添加人员===========" << endl;
	cout << "============================================" << endl;
	cout << "===========2-------------删除人员===========" << endl;
	cout << "============================================" << endl;
	cout << "===========3---------修改人员信息===========" << endl;
	cout << "============================================" << endl;
	cout << "===========4---------查询人员信息===========" << endl;
	cout << "============================================" << endl;
	cout << "===========5-----输出所有人员信息===========" << endl;
	cout << "============================================" << endl;
	cout << "===========6-------------输出总分===========" << endl;
	cout << "============================================" << endl;
	cout << "===========7-------------输出人数===========" << endl;
	cout << "============================================" << endl;
	cout << "===========8-----------输出平均分===========" << endl;
	cout << "============================================" << endl;
	cout << "===========9---------输出分段情况===========" << endl;
	cout << "============================================" << endl;
	cout << "===========0-----------返回上一级===========" << endl;
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

