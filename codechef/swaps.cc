#include <iostream>
using namespace std;

int main() {
    int t;
    string str;
    cin >> t;
    while (t--) {
	cin >> str;
	bool flaf=true;
	int max_so_far, max, l , r, cnt, L, R, M;
	max=max_so_far=0; cnt=0; l=r=L=R=M=0;
	L=R=l=r=-1; M=0;
	int sz = str.size();
	for (int i=0; i<sz; ++i) {
	    if (str[i]=='0') {
		flaf=false;
		if (l==-1) l=i;
		max_so_far++; r=i;
		if (max_so_far>max) max=max_so_far;
	    } else {
		if (max_so_far>1) --max_so_far;
		else {
		    if (l>-1 && r-l+1>M) { L=l; R=r; M=r-l+1; cout << "Updated L=" << L << ", R=" << R << endl; }
		    l=r=-1; max_so_far=0;
		}
	    }
	    cout << "L=" << L << ", R=" << R << ", l=" << l << ", r=" << r << ", M=" << M << endl;
	}
	if (r-l+1>M) { L=l; R=r; }
	cout << "L=" << L << ", R=" << R << endl;
	if (flaf) {
	    cout << sz-1 << endl;
	} else {
	    for (int i=0; i<L; ++i) {
		if (str[i]=='1') ++cnt;
	    }
	    for (int i=L; i<=R && i>=0; ++i) {
		if (str[i]=='0') ++cnt;
	    }
	    for (int i=R+1; i<sz; ++i) {
		if (str[i]=='1') ++cnt;
	    }
	    cout << cnt << endl;
	}
    }
    return 0;
}
