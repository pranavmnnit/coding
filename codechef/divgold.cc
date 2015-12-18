#include <iostream>
using namespace std;

int main() {
    int t, sz;
    string s;
    string min;
    int T;
    cin >> T;
    while (T--) {
	cin >> sz;
	cin >> s;
	min = s;
	for (int i = 0; i < sz; ++i) {
	    for (int j = 0; j <= i; ++j) {
		string t = s.substr(0, j) + s.substr(i, 1) + s.substr(j, i-j) + s.substr(i+1, sz-i);
		if (t < min) min = t;
	    }
	    for (int j = i+1; j < sz; ++j) {
		string t = s.substr(0, i) + s.substr(i+1, j-i) + s.substr(i, 1) + s.substr(j+1, sz-j);
		if (t < min) min = t;
	    }
	}
	cout << min << endl;
    }
    return 0;
}
