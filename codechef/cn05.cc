#include <iostream>
#define ull unsigned long long
using namespace std;
const long long MOD=1000000007;

ull mypow(ull num, ull po) {
    ull result=1;
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

int main() {
    ull T, N;
    cin >> T;
    while (T--) {
	cin >> N;
	ull res = (7*mypow(3, N))%MOD;
	if ((N%2)==0)
	    cout << (((res+1)%MOD)/4) << endl;
	else
	    cout << (((res-1+MOD)%MOD)/4) << endl;
    }
    return 0;
}
