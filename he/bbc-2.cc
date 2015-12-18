#include <iostream>
#include <vector>
#include <cstring>
#define tr(object, it) \
    for((typeof object.begin()) it = object.begin(); it != object.end(); ++it)
using namespace std;

int Z[120010] = {0};

int main() {
    int n, a, b, q;
    vector<string> strs;
    string s, pat;
    cin >> n;
    while (n--) {
	cin >> s;
	strs.push_back(s);
    }
    cin >> q;
    while (q--) {
	int cnt = 0;
	cin >> a >> b >> pat;
	string temp = pat;
	temp += "$";
	for (int i=a; i<=b; ++i) {
	    temp += strs[i-1];
	    temp += "@";
	}
	int L, R, sz;
	L = R = 0;
	sz = temp.size();
	for (int i=1; i<sz; ++i) {
	    if (temp[i] == '@') continue;
	    if (i>R) {
		L = R = i;
		while ((R<sz) && (temp[R] == temp[R-L])) ++R;
		Z[i] = R-L; --R;
	    } else {
		int k = i-L;
		if (Z[k] < R-i+1) {
		    Z[i] = Z[k];
		} else {
		    L = i;
		    while ((R<sz) && (temp[R] == temp[R-L])) ++R;
		    Z[i] = R-L; --R;
		}
	    }
	}
	int szp = pat.size();
	for (int i=szp+1; i<sz;) {
	    //cout << "Z= " << Z[i] << endl;
	    if (Z[i] == szp)  {
		++cnt;
		while (temp[i] != '@') ++i;
	    }
	    ++i;
	}
	cout << cnt << endl;
    }
    return 0;
}
