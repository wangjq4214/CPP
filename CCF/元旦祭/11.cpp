//11
#include <iostream>

using namespace std;

int main() {
	int suma = 0, sumb = 0;
	int N, NA, NB;
	cin >> N >> NA >> NB;
	int xa[NA];
	int xb[NB];
	int vote[5][5] = {{0, 0, 1, 1, 0}, {1, 0, 0, 1, 0}, {0, 1, 0, 0, 1}, {0, 0, 1, 0, 1}, {1, 1, 0, 0, 0}};
	
	for (int i = 0; i < NA; i++) {
		cin >> xa[i];
	}
	
	for (int i = 0; i < NB; i++) {
		cin >> xb[i];
	}
	
	for (int i = 0; i < N; i++) {
		suma += vote[xa[i % NA]][xb[i % NB]];
		sumb += vote[xb[i % NB]][xa[i % NA]];
	}
	
	cout << suma << " " << sumb;
}
