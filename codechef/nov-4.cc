#include <iostream>
using namespace std;
#define MOD 1000000007

long long F[100010] = {0};

inline long long mypow(long long num) { //returns num^num % MOD
    long long result=1;
    long long po = num;
    while (po) {
	if (po%2==0) {
	    num *= num;
	    num %= MOD;
	    po/=2;
	} else {
	    result *= num;
	    result %= MOD;
	    po--;
	}
    }
    return result;
}

void calcAll() {
    for (int i=2; i<=100009; ++i) {
	F[i] = F[i-1]*mypow(i);
	F[i] = F[i]%MOD;
    }
}

int main() {
    F[1] = 1;
    calcAll();
    long T, N, M, Q, r;
    cin >> T;
    while (T--) {
	cin >> N >> M >> Q;
	while (Q--) {
	    cin >> r;
	    cout << (F[N]/(F[r]*F[N-r]))%M << endl;
	}
    }
    return 0;
}
