#include <iostream>
using namespace std;

int _gcd(int a, int b) {
    if (!a) return b;
    if (!b) return a;
    if (a>=b) {
	return _gcd(a%b, b);
    } else {
	return _gcd(b%a, a);
    }
}

int gcd(int a, int b, int c) {
    return (_gcd(a,_gcd(b,c)));
}

int main() {
    bool primes[61] = {false};
    primes[2] = primes[3] = primes[5] = primes[7] = primes[11] = primes[13] = primes[17] = primes[19] = primes[23] = primes[29] = true;
    primes[31] = primes[41] = primes[43] = primes[47] = primes[53] = primes[59] = true;
    long T, h, m, s;
    int i=0,j=0,k=1,l,gc=0,bc=0;
    long good, bad, cnt;
    long arr[24][61][61][4];
    for (i=0; i<=23; ++i) {
	for (j=0; j<=59; ++j) {
	    for (k=0; k<=59; ++k) {
		for (l=0; l<2; ++l) {
		    arr[i][j][k][l] = 0;
		}
	    }
	}
    }

    for (i=0; i<=23; ++i) {
	for (j=0; j<=59; ++j) {
	    for (k=0; k<=59; ++k) {
		if (gcd(i, j, k) != 1) {
		    arr[i][j][k][1] = gc;
		    arr[i][j][k][0] = ++bc;
		} else {
		    arr[i][j][k][1] = ++gc;
		    arr[i][j][k][0] = bc;
		}
	    }
	}
    }
    cin >> T;
    while (T--) {
	good = bad = cnt = 0;
	cin >> h >> m >> s;
	bool flag = true;
	if (!h && !m && !s) flag = false;
	if (s) { s--; }
	else if (m) { m--; s=59; }
	else if (h) { h--; m=s=59; }
	bad += arr[23][59][59][0] - (flag?arr[h][m][s][0]:0);
	good += arr[23][59][59][1] - (flag?arr[h][m][s][1]:0);
	if (good && bad) {
	    int g = _gcd(good, bad);
	    //cout << "g=" << g << endl;
	    cout << bad/g << ":" << good/g << endl;
	} else {
	    cout << bad << ":" << good << endl;
	}
    }
    return 0;
}
