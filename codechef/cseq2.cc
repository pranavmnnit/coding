#include <iostream>
#include <cstdio>
#include <cassert>
#define ull unsigned long long
using namespace std;

const ull MOD = 1000003;

ull fact[MOD+1];
ull inv[MOD+1];

ull pow(ull a, ull b, ull MOD)
{
    ull x=1,y=a,z;
    while(b > 0)
    {
        if(b%2 == 1)
        {
            z=(x*y);
	    //assert(((ull)(z/y) == x) && ((ull)(z/x) == y));
	    x=(x*y);
            if(x>MOD) x%=MOD;
        }
        z = (y*y);
	//assert(z/y == y);
	y = (y*y);
        if(y>MOD) y%=MOD;
        b /= 2;
    }
    return x;
}

void Do() {
    ull t, p , q;
    p = q = 1;
    fact[0] = inv[0] = 1;
    for (t = 1; t <= MOD; ++t) {
	p *= t;
	p %= MOD;
	fact[t] = p;

	q *= pow(t, MOD-2, MOD);
	q %= MOD;
	inv[t] = q;
    }
}

int main() {
    int t;
    ull n, l, r;
    Do();
    scanf("%d", &t);
    while (t--) {
	ull res = 1;
	scanf("%llu %llu %llu", &n, &l, &r);
	ull k = (r-l+1);
	ull N = (k+n);
	ull R = n;
	while (N && R) {
	    ull N1 = N%MOD; ull R1=R%MOD;
	    if (N1 < R1) { res = 0; break; }
	    res = (res * fact[N1])%MOD;
	    res = (res * inv[R1])%MOD;
	    res = (res * inv[N1-R1])%MOD;
	    res %= MOD;
	    N /= MOD;
	    R /= MOD;
	}
	res = (res + MOD - 1)%MOD;
	printf("%llu\n", res);
    }
    return 0;
}
