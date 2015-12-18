#include <cstring>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#define tr(object, it) \
    for (typeof(object.begin()) it = object.begin(); it != object.end(); ++it)
#define for0n(i, n) for(i=0;i<n;i++)
const long long mod = 1e9+7;

map<char, string> enc;
long fail[2000020];

void failure(string& str, long* fail) {
    long sz = str.size();
    long j;
    fail[0] = fail[1] = 0;
    for (long i=2; i <= sz; i++) {
	j = fail[i-1];
	while (1) {
	    if (str[i-1] == str[j]) {
		fail[i] = j+1; break;
	    }
	    if (!j) { fail[i] = 0; break; }
	    j = fail[j];
	}
    }
}

//mod
long long pow2(long long N) {
    long long in = 0;
    if (N == 0) return 1;
    in = pow2(N/2);
    in *= in;
    in %= mod;
    if (N%2 != 0) {
	in *= 2;
	in %= mod;
    }
    return in;
}

//mod
long long E(string& str) {
    long sz = str.size();
    if (sz == 0) return 0;
    long long sum = pow2(sz);
    sum %= mod;
    long j;
    j = fail[sz];
    while (j) {
	sum += pow2(j);
	sum %= mod;
	j = fail[j];
    }
    return sum;
}

int main() {
    long Tc, i, j, ma;
    long N, M;
    string T, P;
    char s11[200001], s22[200001];
    bool found=false;
    enc['a'] = "00000";
    enc['b'] = "00001";
    enc['c'] = "00010";
    enc['d'] = "00011";
    enc['e'] = "00100";
    enc['f'] = "00101";
    enc['g'] = "00110";
    enc['h'] = "00111";
    enc['i'] = "01000";
    enc['j'] = "01001";
    enc['k'] = "01010";
    enc['l'] = "01011";
    enc['m'] = "01100";
    enc['n'] = "01101";
    enc['o'] = "01110";
    enc['p'] = "01111";
    enc['q'] = "10000";
    enc['r'] = "10001";
    enc['s'] = "10010";
    enc['t'] = "10011";
    enc['u'] = "10100";
    enc['v'] = "10101";
    enc['w'] = "10110";
    enc['x'] = "10111";
    enc['y'] = "11000";
    enc['z'] = "11001";
    enc['A'] = "11010";
    enc['B'] = "11011";
    enc['C'] = "11100";
    enc['D'] = "11101";
    enc['E'] = "11110";
    enc['F'] = "11111";
    int ct = 1;

    scanf("%d", &Tc);
    //cin >> Tc;
    while (Tc--) {
	//cout << "test case: " << ct; ct++;
	scanf("%ld %s %ld %s", &N, s11, &M, s22);
	string s1(s11); string s2(s22);
	//cin >> N >> s1 >> M >> s2;
	//cout << "hi" << endl;
	memset(fail, 0, sizeof(int)*1000010); ma=0; found=false;
	//cout << "hi" << endl;
	//s1 = s11; s2 = s22;
	T = P = "";

	long n1 = N/5;
	for0n(i,n1) {
	    T += enc[s1[i]];
	}
	if (N%5 != 0) {
	    string t = enc[s1[n1]].substr(0, N%5);
	    T += t;
	}
	//cout << "T= " << T << ", size= " << T.size() << endl;

	n1 = M/5;
	for0n(i,n1) {
	    P += enc[s2[i]];
	}
	if (M%5 != 0) {
	    string t = enc[s2[n1]].substr(0, M%5);
	    P += t;
	}
	//cout << "P= " << P << ", size= " << P.size() << endl;
	failure(T, fail);
	long long et = E(T);
	//if already done
	if (M >= N) {
	    i=j=0;
	    while (1) {
		if (j == M) break;
		if (T[i] == P[j]) {
		    ++i; ++j;
		    if (i == N) { cout << 0 << endl;/* cout << "found at " << i << endl;*/ found = true; break; }
		    continue;
		} else if (i>0) i = fail[i];
		else ++j;
	    }
	}
	if (found) continue;

	string temp = T+P;
	//cout << "temp= " << temp << endl;
	memset(fail, 0, sizeof(long)*temp.size());
	failure(temp, fail);
	ma = fail[temp.size()];
	while (ma > M) {
	    //cout << "ma inside= " << ma << endl;
	    ma = fail[ma];
	}
	//cout << "ma =" << ma << ", M= " << M << endl;

	P = P.substr(M-ma,ma);
	memset(fail, 0, sizeof(long)*P.size());
	failure(P, fail);
	long long ep = E(P);
	//cout << "P= " << P << endl;
	printf("%ld\n", (et-ep+mod)%mod);
    }
    return 0;
}
