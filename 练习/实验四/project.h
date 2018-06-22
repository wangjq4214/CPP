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
//结点定义 

class Project {
	private:
		Project_Data *head;
		Project_Data *point;
		double length;//静态计数
		double sum;//静态求和
		double aver;//静态平均值
		int part[4];//静态分段
		int Find();
	public:
		Project();//构造函数
		void Filein();//文件读入
		void Fileout();//写入文件
		friend istream& operator >>(istream&, Project&);//重载输入
		friend ostream& operator <<(ostream&, Project&);//重载输出
		void sum_sum();//求总分 
		void sum_count1();//求总人数
		void sum_count2();
		void average();//求平均成绩
		void census();//统计分段情况
		void clean();//删除内容
		void revise();//修改内容
		void find_it();//查询数据
		~Project();//析构函数
};

#endif
