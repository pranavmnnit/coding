#include <iostream>
#define max(a,b) (a>b?a:b);
using namespace std;

long F(string str) {
    long b=0, mb=0;
    long sz = str.size();
    for (long i=0; i< sz; ++i) {
	if (str[i] == '(') {
	    b++;
	} else {
	    b--;
	}
	mb = max(mb, b);
    }
    return mb;
}

int main() {
    long T;
    string str;
    cin >> T;
    while (T--) {
	cin >> str;
	long b = F(str);
	for (long i=0; i<b; ++i) {
	    cout << '(';
	}
	for (long i=0; i<b; ++i) {
	    cout << ')';
	}
	cout << endl;
    }
    return 0;
}

