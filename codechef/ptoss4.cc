#include <cstring>
#include <iostream>
using namespace std;
#define for0n(i, n) for(i=0;i<n;i++)
const long long mod = 1e9+7;

int fail[2000020] = {0};
int pow[1000010] = {0};

void calcpow() {
    for (int i=1;i<1000010;++i) {
	pow[i] = pow[i-1]*2;
	pow[i] %= mod;
    }
}

void failure(string& str, int K) {
    int sz = str.size();
    int j;
    if (K && K<2) return;
    int i = (K?K:2);
    for (; i <= sz; i++) {
	j = fail[i-1];
	while (j && (str[i-1] != str[j])) j = fail[j];
	if (str[i-1] == str[j]) fail[i] = j+1;
    }
}

//mod
long long E(string& str, int idx) {
    int sz = str.size();
    if (sz == 0) return 0;
    long long sum = pow[sz];
    sum %= mod;
    int j;
    j = fail[sz];
    while (j > idx) {
	sum += pow[j];
	sum %= mod;
	j = fail[j];
    }
    return sum;
}

int main() {
    int Tc, i, j, ma;
    int N, M;
    int ch;
    string T, P;
    char s1[200001], s2[200001];
    bool found=false;
    int ct = 1;
    pow[0] = 1;
    calcpow();

    scanf("%d", &Tc);
    while (Tc--) {
	//cout << "ct= " << ct << endl; ++ct;
	scanf("%d %s %d %s", &N, s1, &M, s2);
	ma=0; found=false;
	T = P = "";

	int n1 = N/5;
	for0n(i,n1) {
	    if (s1[i] <= 'F') ch = s1[i]-'A'+26;
	    else ch = s1[i]-'a';
	    T += (ch&16)?'1':'0';
	    T += (ch&8)?'1':'0';
	    T += (ch&4)?'1':'0';
	    T += (ch&2)?'1':'0';
	    T += (ch&1)?'1':'0';
	}
	if (N%5 != 0) {
		if (s1[n1] <= 'F') ch = s1[n1]-'A'+26;
		else ch = s1[n1]-'a';
		int mo = N%5;
		int a = 16;
		while (mo--) {
		    T += (ch&a)?'1':'0';
		    a >>= 1;
		}
	}

	n1 = M/5;
	for0n(i,n1) {
	    if (s2[i] <= 'F') ch = s2[i]-'A'+26;
	    else ch = s2[i]-'a';
	    P += (ch&16)?'1':'0';
	    P += (ch&8)?'1':'0';
	    P += (ch&4)?'1':'0';
	    P += (ch&2)?'1':'0';
	    P += (ch&1)?'1':'0';
	}
	if (M%5 != 0) {
		if (s2[n1] <= 'F') ch = s2[n1]-'A'+26;
		else ch = s2[n1]-'a';
		int mo = M%5;
		int a = 16;
		while (mo--) {
		    P += (ch&a)?'1':'0';
		    a >>= 1;
		}
	}
	failure(T, 0);
	//if already done
	if (M >= N) {
	    i=j=0;
	    while (1) {
		if (j >= M) break;
		if (T[i] == P[j]) {
		    ++i; ++j;
		    if (i == N) { cout << 0 << endl; found = true; break; }
		} else if (i>0) i = fail[i];
		else ++j;
	    }
	}
	if (found) continue;

	string temp = T+P;
	failure(temp, N);
	ma = fail[temp.size()];
	while (ma && (ma > M)) {
	    ma = fail[ma];
	}

	P = P.substr(M-ma,ma);
	long long et = E(T,0);
	long long ep = E(P,0);
	printf("%ld\n", (et-ep+mod)%mod);
    }
    //(void)gettimeofday(&end, NULL);
    //cout << "time taken= " << gettimediff(start, end);
    return 0;
}
