#include <iostream>
using namespace std;

int main() {
    int t, n, k;
    bool flag=0;
    string str;
    cin >> t;
    while  (t--) {
	flag=1;
	cin >> n >> k;
	cin >> str;
	int d=0;
	for (int i=0; i<n; ++i) {
	    if (str[i]=='#') {
		d++;
		if (d==k) { flag=0; break; }
	    } else {
		d=0;
	    }
	}
	if (flag) cout << "YES" << endl;
	else cout << "NO" << endl;
    }
    return 0;
}
