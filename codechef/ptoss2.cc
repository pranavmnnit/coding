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
int fail[1000010];

void initE() {
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
}

void failure(string& str, int* fail) {
    long sz = str.size();
    fail[0] = fail[1] = 0;
    for (long i=2; i <= sz; i++) {
	long j = fail[i-1];
	while(1) {
	    if (str[i-1] == str[j]) {
		fail[i] = j+1;
		break;
	    }
	    if (j == 0) {
		fail[i] = 0;
		break;
	    }
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
    bool done[1000010] = {false};
    int sz = str.size();
    long long sum = pow2(sz);
    sum %= mod;
    done[0] = true;
    int k,j;
    memset(fail, 0, sizeof(int)*(sz+1));
    failure(str, fail);
    if (sz == 0) return 0;
    for (int i=0; i<=sz; ++i) {
        if (!done[fail[i]]) {
            done[fail[i]] = true;
            k = 0; j = sz-fail[i];
            while ((j<sz) && (str[k] == str[j])) {
                ++j; ++k;
                if (j == sz) {
                    sum += pow2(fail[i]);
                    sum %= mod;
                    break;
                }
            }
        }
    }
    return sum;
}

int main() {
    long Tc, i, j, ma;
    long N, M;
    string s1, s2, T, P;
    bool found=false;
    initE();

    cin >> Tc;
    while (Tc--) {
	cin >> N >> s1 >> M >> s2;
	memset(fail, 0, sizeof(int)*(N>M?N:M)); ma=0; found=false;
	T = P = "";

	int l = s1.size();
	for0n(i,l) {
	    T += enc[s1[i]];
	}
	T = T.substr(0, N);

	l = s2.size();
	for0n(i,l) {
	    P += enc[s2[i]];
	}
	P = P.substr(0, M);
	failure(T, fail);
	//if already done
	if (M >= N) {
	    i=j=0;
	    while (1) {
		if (i == N || j == M) break;
		if (T[i] == P[j]) {
		    ++i; ++j;
		    if (i == N) { cout << 0 << endl;/* cout << "found at " << i << endl;*/ found = true; break; }
		    continue;
		}
		if (!i) ++j;
		i = fail[i];
	    }
	}
	if (found) continue;

	i = 0;
	if (M > N) {
	    j = (M-N);
	} else j = 0;

	//find larest suffix in P that matches prefix in T
	//adjust M and P
	for (;j<M;++j) {
	    int i1 = 0, j1 = j;
	    while ((j1<M) && (T[i1] == P[j1])) { ++i1; ++j1; }
	    if (j1 == M) { ma = (M-j); break;}
	}
	P = P.substr(M-ma,ma);
	M = ma;
	//cout << "P= " << P << endl;
	cout << (E(T) - E(P) + mod)%mod << endl;
    }
    return 0;
}
