#include <iostream>
using namespace std;

inline bool isPalin(string str, int sz) {
    int i,j;
    for (i=0, j=sz-1; i<=j; ++i, --j) {
	if (str[i] != str[j]) {
	    return false;
	}
    }
    return true;
}

int main() {
    int T, i, j;
    bool done = false;
    string str;
    cin >> T;
    while (T--) {
	done = false;
	cin >> str;
	int sz=str.size();
	i=0; j=sz-1;
	while ((i<=j) && (str[i] == str[j]) ) {
	    ++i; --j;
	}
	if (i<j) {
	    if (isPalin(str.substr(i, j-i), j-i) || isPalin(str.substr(i+1, j-i), j-i)) {
		cout << "YES" << endl;
	    } else {
		cout << "NO" << endl;
	    }
	} else {
	    cout << "YES" << endl;
	}
    }
    return 0;
}
