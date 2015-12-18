#include <iostream>
#define min(a, b) ((a)<(b)?(a):(b))
using namespace std;

int mini(string& str, bool f) {
    int sz=str.size();
    int r=0;
    if (sz==1) return 0;
    if (f==0) { // first ='+'
	for (int i=0; i<sz; ++i) {
	    if (i%2==0) {
		if (str[i]=='-') ++r;
	    } else {
		if (str[i]=='+') ++r;
	    }
	}
    } else { // first = '-'
	for (int i=0; i<sz; ++i) {
	    if (i%2==0) {
		if (str[i]=='+') ++r;
	    } else {
		if (str[i]=='-') ++r;
	    }
	}
    }
    return r;
}

int main() {
    int t;
    string str;
    cin >> t;
    while (t--) {
	cin >> str;
	int sz=str.size();
	cout << min(mini(str, 0), mini(str, 1)) << endl;
    }
    return 0;
}
