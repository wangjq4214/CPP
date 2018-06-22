#ifndef SCIENCE_H
#define SCIENCE_H

#include <iostream>
#include <fstream>
#include <cstring>
#include "postgraduate.h"

using namespace std;

struct Paper {
	int grade;
	string name;
	Paper() {
		grade = 0;
		name = "NULL";
	}
};

class Science_Data:public Postgraduate {
	public:
		string major;
		Paper paper[3];
		double paper_score;
		double total_score;
		Science_Data *next;
	public:
		Science_Data() {
			number = "NULL";
			name = "NULL";
			sex = 'N';
			age = 0;
			course_score = 0;
			major = "NULL";
			paper_score = 0;
			total_score = 0;
			next = NULL;
		}
};
//��㶨�� 

class Science {
	private:
		Science_Data *head;
		Science_Data *point;
		double length;//��̬����
		double sum;//��̬���
		double aver;//��̬ƽ��ֵ
		int part[4];//��̬�ֶ�
		int Find();
	public:
		Science();//���캯��
		void Filein();//�ļ�����
		void Fileout();//д���ļ�
		friend istream& operator >>(istream&, Science&);//��������
		friend ostream& operator <<(ostream&, Science&);//�������
		void sum_sum();//���ܷ� 
		void sum_count1();//��������
		void sum_count2();
		void average();//��ƽ���ɼ�
		void census();//ͳ�Ʒֶ����
		void clean();//ɾ������
		void revise();//�޸�����
		void find_it();//��ѯ����
		~Science();//��������
};

#endif
