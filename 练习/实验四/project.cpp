#include "project.h"

Project::Project() {
	head = NULL;
	point = NULL;
	length = 0;
	sum = 0;
	aver = 0;
	memset(part, 0, sizeof(part));
}

void Project::Filein() {
	ifstream filein("project.txt");
	head = new Project_Data;
	point = head;
	while (!filein.eof()) {
		filein >> point->number;
		filein >> point->name;
		filein >> point->sex;
		filein >> point->age;
		filein >> point->course_score;
		filein >> point->major;
		filein >> point->item.grade;
		filein >> point->item.name;
		filein >> point->item_score;
		filein >> point->total_score;
		point->next = new Project_Data;
		point = point->next;
	}
	filein.close();
}

void Project::Fileout() {
	ofstream fileout("project.txt", ios::trunc);
	point = head;
	while (point->name != "NULL") {
		fileout << point->number << " ";
		fileout << point->name << " ";
		fileout << point->sex << " ";
		fileout << point->age << " ";
		fileout << point->course_score << " ";
		fileout << point->major << " ";
		fileout << point->item.grade << " ";
		fileout << point->item.name << " ";
		fileout << point->item_score << " ";
		fileout << point->total_score << endl;
		point = point->next;
	}
	fileout.close();
}

istream& operator >>(istream &input, Project &in) {
	in.point = new Project_Data;
	cout << "请输入编号：" << endl;
	input >>  in.point->number;
	cout << "请输入姓名：" << endl;
	input >>  in.point->name;
	cout << "请输入性别（男M，女F）：" << endl;
	input >>  in.point->sex;
	cout << "请输入年龄：" << endl;
	input >>  in.point->age;
	cout << "请输入课程成绩：" << endl;
	input >>  in.point->course_score;
	cout << "请输入领域：" << endl;
	input >>  in.point->major;
	cout << "请输入项目的等级（等级为A、B、C）：" << endl;
	input >>  in.point->item.grade;
	while (!(in.point->item.grade >= 'A' && in.point->item.grade <= 'C')) {
		cout << "输入错误请重新输入：" << endl;
		input >> in.point->item.grade;
	}
	cout << "请输入项目的名字：" << endl;
	input >> in.point->item.name;
	if (in.point->item.grade == 'A') {
		in.point->item_score = 90;
	} else if (in.point->item.grade == 'B') {
		in.point->item_score = 75;
	} else {
		in.point->item_score = 60;
	}
	in.point->total_score = in.point->course_score * 0.5 + in.point->item_score * 0.5;
	in.point->next = in.head;
	in.head = in.point;
}

ostream& operator <<(ostream &output, Project &out) {
	out.point = out.head;
	while (out.point->name != "NULL") {
		cout << "编号：" << out.point->number << endl;
		cout << "姓名：" << out.point->name << endl;
		cout << "性别：" << out.point->sex << endl;
		cout << "年龄：" << out.point->age << endl;
		cout << "课程成绩：" << out.point->course_score << endl;
		cout << "领域：" << out.point->major << endl;
		cout << "项目等级：" << out.point->item.grade << endl;
		cout << "项目名字：" << out.point->item.name << endl;
		cout << "项目成绩：" << out.point->item_score << endl;
		cout << "总成绩：" << out.point->total_score << endl;
		cout << endl;
		out.point = out.point->next;
	}
}

void Project::sum_sum() {
	point = head;
	while (point->name != "NULL") {
		sum += point->total_score;
		point = point->next;
	}
	cout << "总分为" << sum << "分" << endl;
}

void Project::sum_count1() {
	point = head;
	while (point->name != "NULL") {
		length++;
		point = point->next;
	}
}

void Project::sum_count2() {
	point = head;
	while (point->name != "NULL") {
		length++;
		point = point->next;
	}
	cout << "共有学术硕士" << length << "人" << endl;
}

void Project::average() {
	point = head;
	while (point->name != "NULL") {
		sum += point->total_score;
		point = point->next;
	}
	sum_count1();
	aver = sum / length;
	cout << "平均分为" << aver << "分" << endl;
}

void Project::census() {
	sum_count1();
	point = head;
	while (point->name != "NULL") {
		if(point->total_score < 60)
			part[0]++;
		if(point->total_score < 80 && point->total_score > 60)
			part[1]++;
		if(point->total_score < 90 && point->total_score > 80)
			part[2]++;
		if(point->total_score < 100 && point->total_score > 90)
			part[3]++;
		point = point->next;
	}

	cout << "优秀人数：" << part[3] << "  占总人数" << (part[3] / length) * 100 << "%" << endl;
	cout << "良好人数：" << part[2] << "  占总人数" << (part[2] / length) * 100 << "%" << endl;
	cout << "及格人数：" << part[1] << "  占总人数" << (part[1] / length) * 100 << "%" << endl;
	cout << "不及格人数：" << part[0] << "  占总人数" << (part[0] / length) * 100 << "%" << endl;
}

int Project::Find() {
	point = head;
	while (point->name != "NULL") {
		length++;
		point = point->next;
	}
	int n, count = 1;
	point = head;
	cout << "请输入查询方式：" << endl;
	cout << "1-----按编号查找" << endl;
	cout << "2-----按姓名查找" << endl;
	cin >> n;
	if (n == 1) {
		string f1;
		cout << "请输入编号：" << endl;
		cin >> f1;
		while (point->number != f1 && point->next != NULL) {
			count++;
			point = point->next;
		}
	} else if (n == 2) {
		string f2;
		cout << "请输入姓名：" << endl;
		cin >> f2;
		while (point->name != f2 && point->next != NULL) {
			count++;
			point = point->next;
		}
	} else {
		cout << "错误请重新输入：" << endl;
		cout << "1-----按编号查找" << endl;
		cout << "2-----按姓名查找" << endl;
	}
	if (count > length) {
		return -1;
	} else {
		return count;
	}
}

void Project::clean() {
	cout << "======删除======" << endl;
	int pos = Find();
	int count = 1;
	point = head;
	if (pos == -1) {
		cout << "无此人" << endl;
		return;
	} else if (pos == 1) {
		head = point->next;
	} else {
		while (count < pos - 1) {
			point = point->next;
			count++;
		}
		point->next = point->next->next;
	}
	cout << "删除成功" << endl;
}

void Project::revise() {
	cout << "======修改======" << endl;
	int pos = Find();
	int count = 1;
	point = head;
	if (pos == -1) {
		cout << "无此人" << endl;
		return;
	} else if (pos == 1) {
		int n;
		point = head;
		cout << "请输入编号：" << endl;
		cin >> point->number;
		cout << "请输入姓名：" << endl;
		cin >> point->name;
		cout << "请输入性别（男M，女F）：" << endl;
		cin >> point->sex;
		cout << "请输入年龄：" << endl;
		cin >>  point->age;
		cout << "请输入课程成绩：" << endl;
		cin >> point->course_score;
		cout << "请输入领域：" << endl;
		cin >> point->major;
		cout << "请输入项目的等级（等级为A、B、C）：" << endl;
		cin >>  point->item.grade;
		while (!(point->item.grade >= 'A' && point->item.grade <= 'C')) {
			cout << "输入错误请重新输入：" << endl;
			cin >> point->item.grade;
		}
		cout << "请输入项目的名字：" << endl;
		cin >> point->item.name;
		if (point->item.grade == 'A') {
			point->item_score = 90;
		} else if (point->item.grade == 'B') {
			point->item_score = 75;
		} else {
			point->item_score = 60;
		}
		point->total_score = point->course_score * 0.5 + point->item_score * 0.5;
	} else {
		while (count < pos - 1) {
			point = point->next;
			count++;
		}
		point = point->next;
		int n;
		cout << "请输入编号：" << endl;
		cin >> point->number;
		cout << "请输入姓名：" << endl;
		cin >> point->name;
		cout << "请输入性别（男M，女F）：" << endl;
		cin >> point->sex;
		cout << "请输入年龄：" << endl;
		cin >>  point->age;
		cout << "请输入课程成绩：" << endl;
		cin >> point->course_score;
		cout << "请输入专业：" << endl;
		cin >> point->major;
		cout << "请输入项目的等级（等级为A、B、C）：" << endl;
		cin >>  point->item.grade;
		while (!(point->item.grade >= 'A' && point->item.grade <= 'C')) {
			cout << "输入错误请重新输入：" << endl;
			cin >> point->item.grade;
		}
		cout << "请输入论文的名字：" << endl;
		cin >> point->item.name;
		if (point->item.grade == 'A') {
			point->item_score = 90;
		} else if (point->item.grade == 'B') {
			point->item_score = 75;
		} else {
			point->item_score = 60;
		}
		point->total_score = point->course_score * 0.5 + point->item_score * 0.5;
	}
}

void Project::find_it() {
	cout << "======查询======" << endl;
	int pos = Find();
	int count = 1;
	point = head;
	if (pos == -1) {
		cout << "无此人" << endl;
		return;
	} else if (pos == 1) {
		point = head;
		cout << "编号：" << point->number << endl;
		cout << "姓名：" << point->name << endl;
		cout << "性别：" << point->sex << endl;
		cout << "年龄：" << point->age << endl;
		cout << "课程成绩：" << point->course_score << endl;
		cout << "领域：" << point->major << endl;
		cout << "项目等级：" << point->item.grade << endl;
		cout << "项目名字：" << point->item.name << endl;
		cout << "论文成绩：" << point->item_score << endl;
		cout << "总成绩：" << point->total_score << endl;
		cout << endl;
	} else {
		while (count < pos - 1) {
			point = point->next;
			count++;
		}
		point = point->next;
		cout << "编号：" << point->number << endl;
		cout << "姓名：" << point->name << endl;
		cout << "性别：" << point->sex << endl;
		cout << "年龄：" << point->age << endl;
		cout << "课程成绩：" << point->course_score << endl;
		cout << "领域：" << point->major << endl;
		cout << "项目等级：" << point->item.grade << endl;
		cout << "项目名字：" << point->item.name << endl;
		cout << "论文成绩：" << point->item_score << endl;
		cout << "总成绩：" << point->total_score << endl;
		cout << endl;
	}
}

Project::~Project() {
	while (head->next != NULL) {
		point = head;
		head = head->next;
		delete point;
	}
	delete head;
}
