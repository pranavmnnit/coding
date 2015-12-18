#include <iostream>
#include <cassert>
#define SZ(i) (static_cast<int>(i.size()))
using namespace std;

long fail[1000010];
long cnt[1000010];

// Z-funtion Z algo
void Zfun(string& temp, long* Z) {
    int i, L, R, k;
    L = R = 0;
    int sz = SZ(temp);
    for (i=1; i<sz; ++i) {
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
}

int main() {
    int n, k, i;
    string str;
    cin >> n;
    cin >> str;
    cin >> k;
    Zfun(str, fail);
    int sz = SZ(str);
    for (i = 0; i < sz; ++i) {
	cnt[fail[i]]++;
    }
    for (i = SZ(str); i >= 0; --i) {
	cnt[i] += cnt[i+1];
	if (cnt[i] == k-1) break;
    }
    if (i == -1 || i == 0) {
	cout << "0\n" << " " << endl;
    } else {
	cout << i << endl << str.substr(0, i) << endl;
    }
    return 0;
}
