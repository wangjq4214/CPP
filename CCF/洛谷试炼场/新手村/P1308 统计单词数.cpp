#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string found;
    string record;
    getline(cin, found);
    getline(cin, record);
    transform(found.begin(),found.end(),found.begin(),::tolower);
    transform(record.begin(),record.end(),record.begin(),::tolower);
    
    found = ' ' + found + ' ';
    record = ' ' + record + ' ';
    if (record.find(found) == string::npos) {
        cout << -1 << endl;
    } else {
        int alpha = record.find(found);
        int beta = record.find(found), sum = 0;
        while (beta != string::npos) {
            ++sum;
            beta = record.find(found, beta + 1);
        }
        cout << sum << " " << alpha << endl;
    }
    return 0;
}
