#include <iostream>
using namespace std;

inline bool isPalin(string& str, int sz) {
    int i,j;
    for (i=0, j=sz-1; i<=j; ++i, --j) {
	if (str[i] != str[j]) {
	    return false;
	}
    }
    return true;
}

int main() {
    int T;
    bool done = false;
    string str;
    cin >> T;
    while (T--) {
	done = false;
	cin >> str;
	int sz=str.size();
	for (int i=0; i<sz; ++i) {
	    string s2 = str.substr(0,i) + str.substr(i+1, sz-i-1);
	    if (isPalin(s2, sz-1)) {
		cout << "YES" << endl;
		done = true;
		break;
	    }
	}
	if (!done) {
	    cout << "NO" << endl;
	}
    }
    return 0;
}
