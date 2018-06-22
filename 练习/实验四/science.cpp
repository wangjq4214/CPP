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
	cout << "������רҵ��" << endl;
	input >>  in.point->major;
	cout << "������������Ŀ�����3ƪ����" << endl;
	cin >> n;
	while (!(n >= 0 && n <= 3)) {
		cout << "����������������룺" << endl;
		cin >> n;
	}

	for (int i = 0; i < n; i++) {
		cout << "����������" << i + 1 << "�ĵȼ����ȼ�Ϊ1��2��3����" << endl;
		input >>  in.point->paper[i].grade;
		while (!(in.point->paper[i].grade >= 1 && in.point->paper[i].grade <= 3)) {
			cout << "����������������룺" << endl;
			input >> in.point->paper[i].grade;
		}
		in.point->paper_score += in.point->paper[i].grade * 10;
		cout << "����������" << i + 1 << "�����֣�" << endl;
		input >> in.point->paper[i].name;
	}

	in.point->total_score = in.point->course_score * 0.7 + in.point->paper_score * 0.3;
	in.point->next = in.head;
	in.head = in.point;
}

ostream& operator <<(ostream &output, Science &out) {
	out.point = out.head;
	while (out.point->name != "NULL") {
		cout << "��ţ�" << out.point->number << endl;
		cout << "������" << out.point->name << endl;
		cout << "�Ա�" << out.point->sex << endl;
		cout << "���䣺" << out.point->age << endl;
		cout << "�γ̳ɼ���" << out.point->course_score << endl;
		cout << "רҵ��" << out.point->major << endl;
		cout << "���ģ�" << endl;
		for (int i = 0; i < 3; i++) {
			cout << "    ����" << i + 1 << "�ȼ���" << out.point->paper[i].grade << endl;
			cout << "    ����" << i + 1 << "���֣�" << out.point->paper[i].name << endl;
		}
		cout << "���ĳɼ���" << out.point->paper_score << endl;
		cout << "�ܳɼ���" << out.point->total_score << endl;
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
	cout << "�ܷ�Ϊ" << sum << "��" << endl;
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
	cout << "����ѧ��˶ʿ" << length << "��" << endl;
}

void Science::average() {
	point = head;
	while (point->name != "NULL") {
		sum += point->total_score;
		point = point->next;
	}
	sum_count1();
	aver = sum / length;
	cout << "ƽ����Ϊ" << aver << "��" << endl;
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

	cout << "����������" << part[3] << "  ռ������" << (part[3] / length) * 100 << "%" << endl;
	cout << "����������" << part[2] << "  ռ������" << (part[2] / length) * 100 << "%" << endl;
	cout << "����������" << part[1] << "  ռ������" << (part[1] / length) * 100 << "%" << endl;
	cout << "������������" << part[0] << "  ռ������" << (part[0] / length) * 100 << "%" << endl;
}

int Science::Find() {
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

void Science::clean() {
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

void Science::revise() {
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
		cout << "������רҵ��" << endl;
		cin >> point->major;
		cout << "������������Ŀ�����3ƪ����" << endl;
		cin >> n;
		while (!(n >= 0 && n <= 3)) {
			cout << "����������������룺" << endl;
			cin >> n;
		}

		for (int i = 0; i < n; i++) {
			cout << "����������" << i + 1 << "�ĵȼ����ȼ�Ϊ1��2��3����" << endl;
			cin >> point->paper[i].grade;
			while (!(point->paper[i].grade >= 1 && point->paper[i].grade <= 3)) {
				cout << "����������������룺" << endl;
				cin >> point->paper[i].grade;
			}
			point->paper_score += point->paper[i].grade * 10;
			cout << "����������" << i + 1 << "�����֣�" << endl;
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
		cout << "������������Ŀ�����3ƪ����" << endl;
		cin >> n;
		while (!(n >= 0 && n <= 3)) {
			cout << "����������������룺" << endl;
			cin >> n;
		}

		for (int i = 0; i < n; i++) {
			cout << "����������" << i + 1 << "�ĵȼ����ȼ�Ϊ1��2��3����" << endl;
			cin >> point->paper[i].grade;
			while (!(point->paper[i].grade >= 1 && point->paper[i].grade <= 3)) {
				cout << "����������������룺" << endl;
				cin >> point->paper[i].grade;
			}
			point->paper_score += point->paper[i].grade * 10;
			cout << "����������" << i + 1 << "�����֣�" << endl;
			cin >> point->paper[i].name;
		}

		point->total_score = point->course_score * 0.7 + point->paper_score * 0.3;
	}
}

void Science::find_it() {
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
		cout << "רҵ��" << point->major << endl;
		cout << "���ģ�" << endl;
		for (int i = 0; i < 3; i++) {
			cout << "    ����" << i + 1 << "�ȼ���" << point->paper[i].grade << endl;
			cout << "    ����" << i + 1 << "���֣�" << point->paper[i].name << endl;
		}
		cout << "���ĳɼ���" << point->paper_score << endl;
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
		cout << "רҵ��" << point->major << endl;
		cout << "���ģ�" << endl;
		for (int i = 0; i < 3; i++) {
			cout << "    ����" << i + 1 << "�ȼ���" << point->paper[i].grade << endl;
			cout << "    ����" << i + 1 << "���֣�" << point->paper[i].name << endl;
		}
		cout << "���ĳɼ���" << point->paper_score << endl;
		cout << "�ܳɼ���" << point->total_score << endl;
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
