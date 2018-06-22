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
//结点定义 

class Science {
	private:
		Science_Data *head;
		Science_Data *point;
		double length;//静态计数
		double sum;//静态求和
		double aver;//静态平均值
		int part[4];//静态分段
		int Find();
	public:
		Science();//构造函数
		void Filein();//文件读入
		void Fileout();//写入文件
		friend istream& operator >>(istream&, Science&);//重载输入
		friend ostream& operator <<(ostream&, Science&);//重载输出
		void sum_sum();//求总分 
		void sum_count1();//求总人数
		void sum_count2();
		void average();//求平均成绩
		void census();//统计分段情况
		void clean();//删除内容
		void revise();//修改内容
		void find_it();//查询数据
		~Science();//析构函数
};

#endif
