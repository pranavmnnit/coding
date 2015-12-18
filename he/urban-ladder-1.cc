#include <iostream>
using namespace std;

int main() {
    int t;
    string s;
    cin >> t;
    while (t--) {
	cin >> s;
	int sz = static_cast<int>(s.size());
	bool greater = true;
	int last = sz-1;
	for (int i = sz-1; i >= 0; --i) {
	    if (greater) {
		greater = false;
		last = i;
		if (s[i] >= '5') {
		    s[i] = '3';
		    greater = true;
		} else if (s[i] == '3' || s[i] == '4') {
		    s[i] = '5';
		} else {
		    s[i] = '3';
		}
	    } else {
		if (s[i] < '3') {
		    s[i] = '3'; last = i;
		} else if (s[i] == '4') {
		    s[i] = '5'; last = i;
		} else if (s[i] > '5') {
		    s[i] = '3'; last = i;
		    greater = true;
		}
	    }
	}
	if (greater) {
	    for (int i = 0; i <= sz; ++i) {
		cout << 3;
	    }
	    cout << endl;
	} else if (greater == sz-1) {
	    cout << s << endl;
	} else {
	    for (int i = last+1; i < sz; ++i) {
		s[i] = '3';
	    }
	    cout << s << endl;
	}
    }
    return 0;
}
