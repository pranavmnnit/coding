#include <iostream>
using namespace std;

int req[255];
int given[255];

int main() {
    string s, t;
    cin >> s >> t;
    int sz = s.size();
    for (int i = 0; i < sz; ++i) {
	req[s[i]]++;
    }
    sz = t.size();
    for (int i = 0; i < sz; ++i) {
	given[t[i]]++;
    }
    int y = 0, w = 0;
    for (int i = 65; i <= 90; ++i) {
	if (!req[i]) continue;
	if (given[i] >= req[i]) {
	    y += req[i]; given[i] -= req[i]; req[i] = 0;
	} else if (given[i]) {
	    y += given[i]; req[i] -= given[i]; given[i] = 0;
	}
    }
    for (int i = 97; i <= 122; ++i) {
	if (!req[i]) continue;
	if (given[i] >= req[i]) {
	    y += req[i]; given[i] -= req[i]; req[i] = 0;
	} else if (given[i]) {
	    y += given[i]; req[i] -= given[i]; given[i] = 0;
	}
    }
    for (int i = 65; i <= 90; ++i) {
	if (!req[i]) continue;
	if (given[i+32] >= req[i]) {
	   w += req[i]; given[i+32] -= req[i]; req[i] = 0;
	} else {
	   w += given[i+32]; given[i+32] -= req[i]; req[i] = 0;
	}
    }
    for (int i = 97; i <= 122; ++i) {
	if (!req[i]) continue;
	if (given[i-32] >= req[i]) {
	    w += req[i]; given[i-32] -= req[i]; req[i] = 0;
	} else {
	    w += given[i-32]; given[i-32] -= req[i]; req[i] = 0;
	}
    }
    cout << y << " " << w << endl;
    return 0;
}
