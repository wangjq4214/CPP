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
	cout << "�������ţ�" << endl;
	input >>  in.point->number;
	cout << "������������" << endl;
	input >>  in.point->name;
	cout << "�������Ա���M��ŮF����" << endl;
	input >>  in.point->sex;
	cout << "���������䣺" << endl;
	input >>  in.point->age;
	cout << "������γ̳ɼ���" << endl;
	input >>  in.point->course_score;
	cout << "����������" << endl;
	input >>  in.point->major;
	cout << "��������Ŀ�ĵȼ����ȼ�ΪA��B��C����" << endl;
	input >>  in.point->item.grade;
	while (!(in.point->item.grade >= 'A' && in.point->item.grade <= 'C')) {
		cout << "����������������룺" << endl;
		input >> in.point->item.grade;
	}
	cout << "��������Ŀ�����֣�" << endl;
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
		cout << "��ţ�" << out.point->number << endl;
		cout << "������" << out.point->name << endl;
		cout << "�Ա�" << out.point->sex << endl;
		cout << "���䣺" << out.point->age << endl;
		cout << "�γ̳ɼ���" << out.point->course_score << endl;
		cout << "����" << out.point->major << endl;
		cout << "��Ŀ�ȼ���" << out.point->item.grade << endl;
		cout << "��Ŀ���֣�" << out.point->item.name << endl;
		cout << "��Ŀ�ɼ���" << out.point->item_score << endl;
		cout << "�ܳɼ���" << out.point->total_score << endl;
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
	cout << "�ܷ�Ϊ" << sum << "��" << endl;
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
	cout << "����ѧ��˶ʿ" << length << "��" << endl;
}

void Project::average() {
	point = head;
	while (point->name != "NULL") {
		sum += point->total_score;
		point = point->next;
	}
	sum_count1();
	aver = sum / length;
	cout << "ƽ����Ϊ" << aver << "��" << endl;
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

	cout << "����������" << part[3] << "  ռ������" << (part[3] / length) * 100 << "%" << endl;
	cout << "����������" << part[2] << "  ռ������" << (part[2] / length) * 100 << "%" << endl;
	cout << "����������" << part[1] << "  ռ������" << (part[1] / length) * 100 << "%" << endl;
	cout << "������������" << part[0] << "  ռ������" << (part[0] / length) * 100 << "%" << endl;
}

int Project::Find() {
	point = head;
	while (point->name != "NULL") {
		length++;
		point = point->next;
	}
	int n, count = 1;
	point = head;
	cout << "�������ѯ��ʽ��" << endl;
	cout << "1-----����Ų���" << endl;
	cout << "2-----����������" << endl;
	cin >> n;
	if (n == 1) {
		string f1;
		cout << "�������ţ�" << endl;
		cin >> f1;
		while (point->number != f1 && point->next != NULL) {
			count++;
			point = point->next;
		}
	} else if (n == 2) {
		string f2;
		cout << "������������" << endl;
		cin >> f2;
		while (point->name != f2 && point->next != NULL) {
			count++;
			point = point->next;
		}
	} else {
		cout << "�������������룺" << endl;
		cout << "1-----����Ų���" << endl;
		cout << "2-----����������" << endl;
	}
	if (count > length) {
		return -1;
	} else {
		return count;
	}
}

void Project::clean() {
	cout << "======ɾ��======" << endl;
	int pos = Find();
	int count = 1;
	point = head;
	if (pos == -1) {
		cout << "�޴���" << endl;
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
	cout << "ɾ���ɹ�" << endl;
}

void Project::revise() {
	cout << "======�޸�======" << endl;
	int pos = Find();
	int count = 1;
	point = head;
	if (pos == -1) {
		cout << "�޴���" << endl;
		return;
	} else if (pos == 1) {
		int n;
		point = head;
		cout << "�������ţ�" << endl;
		cin >> point->number;
		cout << "������������" << endl;
		cin >> point->name;
		cout << "�������Ա���M��ŮF����" << endl;
		cin >> point->sex;
		cout << "���������䣺" << endl;
		cin >>  point->age;
		cout << "������γ̳ɼ���" << endl;
		cin >> point->course_score;
		cout << "����������" << endl;
		cin >> point->major;
		cout << "��������Ŀ�ĵȼ����ȼ�ΪA��B��C����" << endl;
		cin >>  point->item.grade;
		while (!(point->item.grade >= 'A' && point->item.grade <= 'C')) {
			cout << "����������������룺" << endl;
			cin >> point->item.grade;
		}
		cout << "��������Ŀ�����֣�" << endl;
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
		cout << "�������ţ�" << endl;
		cin >> point->number;
		cout << "������������" << endl;
		cin >> point->name;
		cout << "�������Ա���M��ŮF����" << endl;
		cin >> point->sex;
		cout << "���������䣺" << endl;
		cin >>  point->age;
		cout << "������γ̳ɼ���" << endl;
		cin >> point->course_score;
		cout << "������רҵ��" << endl;
		cin >> point->major;
		cout << "��������Ŀ�ĵȼ����ȼ�ΪA��B��C����" << endl;
		cin >>  point->item.grade;
		while (!(point->item.grade >= 'A' && point->item.grade <= 'C')) {
			cout << "����������������룺" << endl;
			cin >> point->item.grade;
		}
		cout << "���������ĵ����֣�" << endl;
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
	cout << "======��ѯ======" << endl;
	int pos = Find();
	int count = 1;
	point = head;
	if (pos == -1) {
		cout << "�޴���" << endl;
		return;
	} else if (pos == 1) {
		point = head;
		cout << "��ţ�" << point->number << endl;
		cout << "������" << point->name << endl;
		cout << "�Ա�" << point->sex << endl;
		cout << "���䣺" << point->age << endl;
		cout << "�γ̳ɼ���" << point->course_score << endl;
		cout << "����" << point->major << endl;
		cout << "��Ŀ�ȼ���" << point->item.grade << endl;
		cout << "��Ŀ���֣�" << point->item.name << endl;
		cout << "���ĳɼ���" << point->item_score << endl;
		cout << "�ܳɼ���" << point->total_score << endl;
		cout << endl;
	} else {
		while (count < pos - 1) {
			point = point->next;
			count++;
		}
		point = point->next;
		cout << "��ţ�" << point->number << endl;
		cout << "������" << point->name << endl;
		cout << "�Ա�" << point->sex << endl;
		cout << "���䣺" << point->age << endl;
		cout << "�γ̳ɼ���" << point->course_score << endl;
		cout << "����" << point->major << endl;
		cout << "��Ŀ�ȼ���" << point->item.grade << endl;
		cout << "��Ŀ���֣�" << point->item.name << endl;
		cout << "���ĳɼ���" << point->item_score << endl;
		cout << "�ܳɼ���" << point->total_score << endl;
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
