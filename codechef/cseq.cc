#include <iostream>
#include <cstdio>
#include <cassert>
#include <climits>
#define ull unsigned long long
using namespace std;

const ull MOD = 1000003;

/* This function calculates power of p in n! */
ull countFact(ull n, ull p)
{
    ull k=0;
    while (n >= p)
    {
        k += (n/p);
        n /= p;
    }
    return k;
}

ull pow(ull a, ull b, ull MOD)
{
    ull x=1,y=a;
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x=(x*y)%MOD;
            //if(x>MOD) x%=MOD;
        }
        y = (y*y)%MOD;
        //if(y>MOD) y%=MOD;
        b /= 2;
    }
    return x;
}

/*  Modular Multiplicative Inverse
    Using Euler's Theorem
    a^(phi(m)) = 1 (mod m)
    a^(-1) = a^(m-2) (mod m) */
ull InverseEuler(ull n, ull MOD)
{
    return (pow(n,MOD-2,MOD)%MOD);
}

ull factMOD(ull n, ull MOD)
{
    ull res = 1;
    while (n > 0)
    {
        for (ull i=2, m=n%MOD; i<=m; i++)
            res = (res * i) % MOD;
        if ((n/=MOD)%2)
            res = MOD - res;
    }
    return res;
}

ull C(ull n, ull r, ull MOD)
{
    if (countFact(n, MOD) > (countFact(r, MOD) + countFact(n-r, MOD)))
	return(0);

    return (factMOD(n, MOD) *
            ((InverseEuler(factMOD(r, MOD), MOD) * InverseEuler(factMOD(n-r, MOD), MOD)) % MOD)) % MOD;
}

ull lucas(ull m, ull n, ull MOD) {
    ull ans = 1;
    while (m && n) {
	ans = (ans * C(m%MOD, n%MOD, MOD)) % MOD;
	m /= MOD;
	n /= MOD;
    }
    return ans;
}

int main() {
    int t;
    ull n, l, r;
    scanf("%d", &t);
    while (t--) {
	scanf("%llu %llu %llu", &n, &l, &r);
	ull k = (r-l+1);
	ull res = lucas(k+n, n+1, MOD)%MOD;
	//ull res = C(k+n, n+1, MOD)%MOD;
	res = (res * ((n+1)%MOD))%MOD;
	res = (res * pow(k, MOD-2, MOD)%MOD)%MOD;
	res = (MOD + res - 1)%MOD;
	printf("%llu\n", res%MOD);
    }
    return 0;
}
