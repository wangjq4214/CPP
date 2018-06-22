//输出真值表
#include <iostream>
#include <string>
#include <map>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

/*
用！表示否定
用&表示合取
用|表示析取
用-表示条件
用=表示双条件
*/

map<char, int> valueMap, valueMap1; // 创建映射
int value = 0;
string input1, input2; // 创建输入的字符串

int changeValue(int); // 处理否定
void changeValue1(int&);
int dealConjunction(int, char, int); // 处理连接词
int dealInner(string&); // 处理最内层
int dealExp(string&); // 处理表达式
void print(int, int);

int main() {
    cout << "请输入合式公式表达式：" << endl;
    cout << "（用！表示否定 用&表示合取 用|表示析取 用-表示条件 用=表示双条件 用小写字母表示命题变元）" << endl;
    cin >> input1;
    input2 = input1;
    // 完成输入

    string::iterator iter1 = input1.begin();
    while (iter1 != input1.end()) {
        if (*iter1 >= 'a' && *iter1 <= 'z') {
            valueMap[*iter1] = 0;
        }
        iter1++;
    }
    // 完成对map的初始化
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
    // 完成真值表输出

    return 0;
}

// 处理否定
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

// 处理连接词
int dealConjunction(int part1, char part2, int part3) {
    switch(part2) {
        case '&': // 合取
            return part1 && part3;
            break;
        case '|': // 析取
            return part1 || part3;
            break;
        case '-': // 条件
            return !(part1 == 1 && part3 == 0);
            break;
        case '=': // 双条件
            return part1 == part3;
            break;
        default:
            cout << "存在错误!" << endl;
            break;
    }
}

// 处理最内层
int dealInner(string &str) {
    int partValue; // 部分的值

    // 对！进行处理
    for (string::iterator iter = str.begin(); iter != str.end(); iter++) {
        if (*iter == '!') {
            string::iterator next = iter + 1; // ！的下一位
            if (*next >= 'a' && *next <= 'z') {
                valueMap[*next] = changeValue(valueMap1[*next]); // 转换真值
            } else {
                changeValue1(valueMap[*next]);
            }
            str.erase(iter); // 删除否定符号
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

// 处理表达式
int dealExp(string &Exp) {
    // 扫描括号
    // 创建记录体
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
        // 找到最内层括号
        for (; i <= addr.size(); i++) {
            if (kind.at(i) == ')')
                break;
        }

        // 取出最内层字符串
        string inner = string(addr.at(i - 1) + 1, addr.at(i));
        value = dealInner(inner);

        static char var = '1';
        valueMap[var] = value; // 进行替换

        // 判断是否为第一项
        bool flag = false;
        string::iterator init;
        if (addr.at(i - 1) == Exp.begin()) {
            flag = true;
        } else {
            init = addr.at(i - 1) - 1;
        }

        Exp.erase(addr.at(i - 1), addr.at(i) + 1); // 删除最内层

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
