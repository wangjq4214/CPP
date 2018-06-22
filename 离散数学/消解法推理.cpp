#include <iostream>
#include <iomanip>

using namespace std;
struct yj {
	string xushu, yuju, liyou;
	int z1, z2;//z1表示是否用过；z2相同的语句均是由一个前提推出的语句
};

string zhuanhuan(int aa) {
	string sss;
	while (aa > 0) {
		char q;
		q = aa % 10 + '0';
		sss = q + sss;
		aa = aa / 10;
	}
	return sss;
}

void xsbs(string &a, int aa) { //每行语句的序数
	string q;
	if (aa > 9) q = zhuanhuan(aa);
	else q = aa + '0';
	a += "(";
	a += q;
	a += ")";
}

void qhjian(string &a1, string &a2, string a) { //前后件函数
	int ii = 0;
	while (a[ii] != '-' && a[ii] != '+' && a[ii] != '=') {
		a1 = a1 + a[ii];
		ii++;
	}
	ii++;
	while (a[ii] != '\0') {
		a2 = a2 + a[ii];
		ii++;
	}
}

void zuhe(string a1, string a2, string &a) { //前后件重新组合
	a = a + a1;
	a = a + '+';
	a = a + a2;
}

string jielun;
string liy[4] = {"前提条件", "条件式转为析取式", "双条件导出的析取式", "消解"};
int xs = 1;
yj gs[100];
int jjj = 1;

void input() {
	while (1) {
		xsbs(gs[xs].xushu, xs);
		gs[xs].z1 = 1;
		getline(cin, gs[xs].yuju);
		if (gs[xs].yuju.length() != 0) {
			string a = gs[xs].yuju;
			gs[xs].liyou = liy[0];
			gs[xs].z2 = jjj;
			if (a.find("!!") != a.npos) {

				while (a.find("!!") != a.npos) { //处理多个"!"
					xs++;
					gs[xs].z1 = 1;
					gs[xs].z2 = jjj;
					xsbs(gs[xs].xushu, xs);
					a.replace(a.find("!!"), 2, "");
					gs[xs].yuju = a;
					gs[xs].liyou = "等值式";
					//xs++;
				}
				xs++;
			} else if (a.find("-") != a.npos) { //find函数判断是否为条件式 并转化为析取
				xs++;
				gs[xs].z1 = 1;
				gs[xs].z2 = jjj;
				xsbs(gs[xs].xushu, xs);
				string a1, a2;
				qhjian(a1, a2, a);
				a1 = '!' + a1;
				zuhe(a1, a2, gs[xs].yuju);
				if (gs[xs].yuju.find("!!") != gs[xs].yuju.npos)
					gs[xs].yuju.replace(gs[xs].yuju.find("!!"), 2, "");
				gs[xs].liyou = gs[xs - 1].xushu + liy[1];
				xs++;
			} else if (a.find("=") != a.npos) { //双条件转析取
				xs++;
				gs[xs].z1 = 1;
				gs[xs].z2 = jjj;
				xsbs(gs[xs].xushu, xs);
				string a1, a2;
				qhjian(a1, a2, a);
				string a11;
				a11 = '!' + a1;
				zuhe(a11, a2, gs[xs].yuju);
				gs[xs].liyou = gs[xs - 1].xushu + liy[2];
				xs++;

				gs[xs].z1 = 1;
				gs[xs].z2 = jjj;
				xsbs(gs[xs].xushu, xs);
				string a22;
				a22 = '!' + a2;
				zuhe(a22, a1, gs[xs].yuju);
				gs[xs].liyou = gs[xs - 2].xushu + liy[2];
				xs++;
			} else {
				xs++;
			}
			jjj++;
		} else break;
	}
}

string tempgs;
int k1[10], kk = 0, k;

int main() {
	cout << "条件：" << endl;
	input();
	cout << "结论：" << endl;
	cin >> jielun;
	for (int j = 1; j < xs; j++) { //寻找文字
		if (gs[j].yuju.length() <= 2) {
			k1[kk] = j;
			kk++;
		}
	}
	for (int u = 0; u < kk; u++) { //前提多个文字
		tempgs = gs[k1[u]].yuju;
		k = k1[u];
		gs[k].z1 = 0;
		int sum1 = 0, sum2 = 1;
		while (sum1 != sum2) {
			sum2 = sum1;
			int j;
			if (tempgs == jielun) break;
			tempgs = '!' + tempgs;
			if (tempgs.find("!!") != tempgs.npos)
				tempgs.replace(tempgs.find("!!"), 2, "");
			for (j = 1; j < xs; j++) {
				if (gs[j].yuju.find(tempgs) != gs[j].yuju.npos
				        && gs[j].yuju.find("+") != gs[j].yuju.npos
				        && gs[j].z1 == 1) {
					int p;
					for (p = 1; p < j; p++) {
						if (gs[p].z2 == gs[j].z2) {
							if (gs[p].z1 == 0) break;
						}
					}
					if (p < j) continue;
					sum1++;
					string tempgs1;
					if (gs[j].yuju.find(tempgs) < gs[j].yuju.find("+")) {
						for (int jj = gs[j].yuju.find("+") + 1; jj < gs[j].yuju.length(); jj++) {
							tempgs1 += gs[j].yuju[jj];
						}
						tempgs = tempgs1;
						gs[j].z1 = 0;
						string q;
						string s;
						xsbs(s, xs);
						gs[xs].xushu = s;
						gs[xs].z1 = 1;
						gs[xs].yuju = tempgs;
						gs[xs].liyou += gs[j].xushu;
						gs[xs].liyou += gs[k].xushu;
						gs[xs].liyou += liy[3];
						xs++;
						k = xs - 1;
					} else {
						for (int jj = 0; jj < gs[j].yuju.find("+"); jj++) {
							tempgs1 += gs[j].yuju[jj];
						}
						tempgs = tempgs1;
						gs[j].z1 = 0;
						string q;
						string s;
						xsbs(s, xs);
						gs[xs].xushu = s;
						gs[xs].z1 = 1;
						gs[xs].yuju = tempgs;
						gs[xs].liyou += gs[j].xushu;
						gs[xs].liyou += gs[k].xushu;
						gs[xs].liyou += liy[3];
						xs++;
						k = xs - 1;
					}
					break;
				}
			}
		}
		if (tempgs == jielun) break;
	}
	if (tempgs == jielun) cout << "我推出来了" << endl;
	else cout << "sorry" << endl;
	for (int i = 1; i < xs; i++) {
		cout << gs[i].xushu << "          ";
		cout << gs[i].yuju;
		cout << "为真           ";
		cout << gs[i].liyou << endl;
	}
	return 0;
}
