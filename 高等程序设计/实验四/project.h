#ifndef PROJECT_H
#define PROJECT_H

#include <iostream>
#include <fstream>
#include <cstring>
#include "postgraduate.h"

using namespace std;

struct Item {
	char grade;
	string name;
	Item() {
		grade = 'N';
		name = "NULL";
	}
};

class Project_Data:public Postgraduate {
	public:
		string major;
		Item item;
		double item_score;
		double total_score;
		Project_Data *next;
	public:
		Project_Data() {
			number = "NULL";
			name = "NULL";
			sex = 'N';
			age = 0;
			course_score = 0;
			major = "NULL";
			item_score = 0;
			total_score = 0;
			next = NULL;
		}
};
//��㶨�� 

class Project {
	private:
		Project_Data *head;
		Project_Data *point;
		double length;//��̬����
		double sum;//��̬���
		double aver;//��̬ƽ��ֵ
		int part[4];//��̬�ֶ�
		int Find();
	public:
		Project();//���캯��
		void Filein();//�ļ�����
		void Fileout();//д���ļ�
		friend istream& operator >>(istream&, Project&);//��������
		friend ostream& operator <<(ostream&, Project&);//�������
		void sum_sum();//���ܷ� 
		void sum_count1();//��������
		void sum_count2();
		void average();//��ƽ���ɼ�
		void census();//ͳ�Ʒֶ����
		void clean();//ɾ������
		void revise();//�޸�����
		void find_it();//��ѯ����
		~Project();//��������
};

#endif
