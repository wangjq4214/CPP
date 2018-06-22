#include "science.h"

Science::Science() {
	head = NULL;
	point = NULL;
	length = 0;
	sum = 0;
	aver = 0;
	memset(part, 0, sizeof(part));
}

void Science::Filein() {
	ifstream filein("science.txt");
	head = new Science_Data;
	point = head;
	while (!filein.eof()) {
		filein >> point->number;
		filein >> point->name;
		filein >> point->sex;
		filein >> point->age;
		filein >> point->course_score;
		filein >> point->major;
		for (int i = 0; i < 3; i++) {
			filein >> point->paper[i].grade;
			filein >> point->paper[i].name;
		}
		filein >> point->paper_score;
		filein >> point->total_score;
		point->next = new Science_Data;
		point = point->next;
	}
	filein.close();
}

void Science::Fileout() {
	ofstream fileout("science.txt", ios::trunc);
	point = head;
	while (point->name != "NULL") {
		fileout << point->number << " ";
		fileout << point->name << " ";
		fileout << point->sex << " ";
		fileout << point->age << " ";
		fileout << point->course_score << " ";
		fileout << point->major << " ";
		for (int i = 0; i < 3; i++) {
			fileout << point->paper[i].grade << " ";
			fileout << point->paper[i].name << " ";
		}
		fileout << point->paper_score << " ";
		fileout << point->total_score << endl;
		point = point->next;
	}
	fileout.close();
}

istream& operator >>(istream &input, Science &in) {
	int n = 0;
	in.point = new Science_Data;
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
	cout << "请输入专业：" << endl;
	input >>  in.point->major;
	cout << "请输入论文数目（最多3篇）：" << endl;
	cin >> n;
	while (!(n >= 0 && n <= 3)) {
		cout << "输入错误请重新输入：" << endl;
		cin >> n;
	}

	for (int i = 0; i < n; i++) {
		cout << "请输入论文" << i + 1 << "的等级（等级为1、2、3）：" << endl;
		input >>  in.point->paper[i].grade;
		while (!(in.point->paper[i].grade >= 1 && in.point->paper[i].grade <= 3)) {
			cout << "输入错误请重新输入：" << endl;
			input >> in.point->paper[i].grade;
		}
		in.point->paper_score += in.point->paper[i].grade * 10;
		cout << "请输入论文" << i + 1 << "的名字：" << endl;
		input >> in.point->paper[i].name;
	}

	in.point->total_score = in.point->course_score * 0.7 + in.point->paper_score * 0.3;
	in.point->next = in.head;
	in.head = in.point;
}

ostream& operator <<(ostream &output, Science &out) {
	out.point = out.head;
	while (out.point->name != "NULL") {
		cout << "编号：" << out.point->number << endl;
		cout << "姓名：" << out.point->name << endl;
		cout << "性别：" << out.point->sex << endl;
		cout << "年龄：" << out.point->age << endl;
		cout << "课程成绩：" << out.point->course_score << endl;
		cout << "专业：" << out.point->major << endl;
		cout << "论文：" << endl;
		for (int i = 0; i < 3; i++) {
			cout << "    论文" << i + 1 << "等级：" << out.point->paper[i].grade << endl;
			cout << "    论文" << i + 1 << "名字：" << out.point->paper[i].name << endl;
		}
		cout << "论文成绩：" << out.point->paper_score << endl;
		cout << "总成绩：" << out.point->total_score << endl;
		cout << endl;
		out.point = out.point->next;
	}
}

void Science::sum_sum() {
	point = head;
	while (point->name != "NULL") {
		sum += point->total_score;
		point = point->next;
	}
	cout << "总分为" << sum << "分" << endl;
}

void Science::sum_count1() {
	point = head;
	while (point->name != "NULL") {
		length++;
		point = point->next;
	}
}

void Science::sum_count2() {
	point = head;
	while (point->name != "NULL") {
		length++;
		point = point->next;
	}
	cout << "共有学术硕士" << length << "人" << endl;
}

void Science::average() {
	point = head;
	while (point->name != "NULL") {
		sum += point->total_score;
		point = point->next;
	}
	sum_count1();
	aver = sum / length;
	cout << "平均分为" << aver << "分" << endl;
}

void Science::census() {
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

int Science::Find() {
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

void Science::clean() {
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

void Science::revise() {
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
		cout << "请输入专业：" << endl;
		cin >> point->major;
		cout << "请输入论文数目（最多3篇）：" << endl;
		cin >> n;
		while (!(n >= 0 && n <= 3)) {
			cout << "输入错误请重新输入：" << endl;
			cin >> n;
		}

		for (int i = 0; i < n; i++) {
			cout << "请输入论文" << i + 1 << "的等级（等级为1、2、3）：" << endl;
			cin >> point->paper[i].grade;
			while (!(point->paper[i].grade >= 1 && point->paper[i].grade <= 3)) {
				cout << "输入错误请重新输入：" << endl;
				cin >> point->paper[i].grade;
			}
			point->paper_score += point->paper[i].grade * 10;
			cout << "请输入论文" << i + 1 << "的名字：" << endl;
			cin >> point->paper[i].name;
		}

		point->total_score = point->course_score * 0.7 + point->paper_score * 0.3;
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
		cout << "请输入论文数目（最多3篇）：" << endl;
		cin >> n;
		while (!(n >= 0 && n <= 3)) {
			cout << "输入错误请重新输入：" << endl;
			cin >> n;
		}

		for (int i = 0; i < n; i++) {
			cout << "请输入论文" << i + 1 << "的等级（等级为1、2、3）：" << endl;
			cin >> point->paper[i].grade;
			while (!(point->paper[i].grade >= 1 && point->paper[i].grade <= 3)) {
				cout << "输入错误请重新输入：" << endl;
				cin >> point->paper[i].grade;
			}
			point->paper_score += point->paper[i].grade * 10;
			cout << "请输入论文" << i + 1 << "的名字：" << endl;
			cin >> point->paper[i].name;
		}

		point->total_score = point->course_score * 0.7 + point->paper_score * 0.3;
	}
}

void Science::find_it() {
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
		cout << "专业：" << point->major << endl;
		cout << "论文：" << endl;
		for (int i = 0; i < 3; i++) {
			cout << "    论文" << i + 1 << "等级：" << point->paper[i].grade << endl;
			cout << "    论文" << i + 1 << "名字：" << point->paper[i].name << endl;
		}
		cout << "论文成绩：" << point->paper_score << endl;
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
		cout << "专业：" << point->major << endl;
		cout << "论文：" << endl;
		for (int i = 0; i < 3; i++) {
			cout << "    论文" << i + 1 << "等级：" << point->paper[i].grade << endl;
			cout << "    论文" << i + 1 << "名字：" << point->paper[i].name << endl;
		}
		cout << "论文成绩：" << point->paper_score << endl;
		cout << "总成绩：" << point->total_score << endl;
		cout << endl;
	}
}

Science::~Science() {
	while (head->next != NULL) {
		point = head;
		head = head->next;
		delete point;
	}
	delete head;
}
