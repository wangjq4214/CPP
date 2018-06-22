//�����ֵ��
#include <iostream>
#include <string>
#include <map>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

/*
�ã���ʾ��
��&��ʾ��ȡ
��|��ʾ��ȡ
��-��ʾ����
��=��ʾ˫����
*/

map<char, int> valueMap, valueMap1; // ����ӳ��
int value = 0;
string input1, input2; // ����������ַ���

int changeValue(int); // �����
void changeValue1(int&);
int dealConjunction(int, char, int); // �������Ӵ�
int dealInner(string&); // �������ڲ�
int dealExp(string&); // ������ʽ
void print(int, int);

int main() {
    cout << "�������ʽ��ʽ���ʽ��" << endl;
    cout << "���ã���ʾ�� ��&��ʾ��ȡ ��|��ʾ��ȡ ��-��ʾ���� ��=��ʾ˫���� ��Сд��ĸ��ʾ�����Ԫ��" << endl;
    cin >> input1;
    input2 = input1;
    // �������

    string::iterator iter1 = input1.begin();
    while (iter1 != input1.end()) {
        if (*iter1 >= 'a' && *iter1 <= 'z') {
            valueMap[*iter1] = 0;
        }
        iter1++;
    }
    // ��ɶ�map�ĳ�ʼ��
    valueMap1 = valueMap;

    for (map<char, int>::iterator iter2 = valueMap.begin(); iter2 != valueMap.end(); iter2++) {
        cout << setw(5) << left << iter2->first;
    }
    cout << setw(30) << left << input2 << endl;

    for (int i = 0; i < pow(2, valueMap1.size()); i++) {
        input1 =input2;
        valueMap = valueMap1;
        int factor = 1;
        for (map<char, int>::iterator iter2 = valueMap.begin(); iter2 != valueMap.end(); iter2++) {
            if ((i & (1 << (valueMap.size() - factor))) == 0) {
                iter2->second = 0;
            } else {
                iter2->second = 1;
            }
            factor++;
        }
        valueMap1 = valueMap;

        int val = dealExp(input1);
        print(val, i);
    }
    // �����ֵ�����

    return 0;
}

// �����
int changeValue(int s) {
    if (s == 0) {
        s = 1;
    } else {
        s = 0;
    }

    return s;
}

void changeValue1(int &s) {
    if (s == 0) {
        s = 1;
    } else {
        s = 0;
    }
}

// �������Ӵ�
int dealConjunction(int part1, char part2, int part3) {
    switch(part2) {
        case '&': // ��ȡ
            return part1 && part3;
            break;
        case '|': // ��ȡ
            return part1 || part3;
            break;
        case '-': // ����
            return !(part1 == 1 && part3 == 0);
            break;
        case '=': // ˫����
            return part1 == part3;
            break;
        default:
            cout << "���ڴ���!" << endl;
            break;
    }
}

// �������ڲ�
int dealInner(string &str) {
    int partValue; // ���ֵ�ֵ

    // �ԣ����д���
    for (string::iterator iter = str.begin(); iter != str.end(); iter++) {
        if (*iter == '!') {
            string::iterator next = iter + 1; // ������һλ
            if (*next >= 'a' && *next <= 'z') {
                valueMap[*next] = changeValue(valueMap1[*next]); // ת����ֵ
            } else {
                changeValue1(valueMap[*next]);
            }
            str.erase(iter); // ɾ���񶨷���
        }
    }

    string::iterator iter = str.begin();
    partValue = valueMap[*iter];
    int leng = str.length();

    if (leng == 1) {
        return partValue;
    } else {
        for(; iter != str.end() - 1;) {
            ++iter;
            char b = *iter;
            partValue = dealConjunction(partValue,b,valueMap[*(++iter)]);
        }
    }

    return partValue;
}

// ������ʽ
int dealExp(string &Exp) {
    // ɨ������
    // ������¼��
    string::iterator iter;
    vector<string::iterator> addr;
    vector<char> kind;

    for (iter = Exp.begin(); iter != Exp.end(); iter++) {
        if (*iter == '(' || *iter == ')') {
            addr.push_back(iter);
            kind.push_back(*iter);
        }
    }

    if (addr.size() == 0) {
        value = dealInner(Exp);
        return value;
    } else {
        int i = 0;
        // �ҵ����ڲ�����
        for (; i <= addr.size(); i++) {
            if (kind.at(i) == ')')
                break;
        }

        // ȡ�����ڲ��ַ���
        string inner = string(addr.at(i - 1) + 1, addr.at(i));
        value = dealInner(inner);

        static char var = '1';
        valueMap[var] = value; // �����滻

        // �ж��Ƿ�Ϊ��һ��
        bool flag = false;
        string::iterator init;
        if (addr.at(i - 1) == Exp.begin()) {
            flag = true;
        } else {
            init = addr.at(i - 1) - 1;
        }

        Exp.erase(addr.at(i - 1), addr.at(i) + 1); // ɾ�����ڲ�

        if (flag == true) {
            Exp = var + Exp;
        } else {
            Exp.insert(init + 1, var);
        }

        var = var + 1;
        value = dealExp(Exp);

        return value;
    }
}

void print(int val, int i) {
    for (map<char, int>::iterator iter2 = valueMap1.begin(); iter2 != valueMap1.end(); iter2++) {
        cout << setw(5) << left << iter2->second;
    }

    cout << setw(30) << left << val << endl;
    return;
}
