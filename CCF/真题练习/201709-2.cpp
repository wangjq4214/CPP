#include <bits/stdc++.h>

using namespace std;
int n, k;
int box[1010];

struct Teacher {
    int key;
    int start;
    int finish;

    Teacher(int w, int s, int c) {
        key = w;
        start = s;
        finish = c;
    }
};

bool compStart(const Teacher &x, const Teacher &y) {
    return x.start < y.start;
}

bool compFinish(const Teacher &x, const Teacher &y) {
    if (x.finish == y.finish) {
        return x.key < y.key;
    }
    return x.finish < y.finish;
}

vector<Teacher> startTime, finishTime;

void findIt(int, int);

int main() {
    cin >> n >> k;
    box[0] = -1;
    for (int i = 1; i <= n; ++i) {
        box[i] = i;
    }

    for (int i = 0; i < k; ++i) {
        int w, s, c;
        cin >> w >> s >> c;
        Teacher temp(w, s, s + c);
        startTime.push_back(temp);
        finishTime.push_back(temp);
    }

    sort(startTime.begin(), startTime.end(), compStart);
    sort(finishTime.begin(), finishTime.end(), compFinish);

    findIt(0, 0);
    for (int i = 1; i <= n; ++i) {
        cout << box[i] << " ";
    }
}

void findIt(int x, int y) {
    if (y >= k) {
        return;
    }

    if (x < k && startTime[x].start < finishTime[y].finish) {
        int *index = find(box, box + n, startTime[x].key);
        *index = 0;
        findIt(++x, y);
    } else {
        int *index = find(box, box + n, 0);
        *index = finishTime[y].key;
        findIt(x, ++y);
    }
}
