#include <stdio.h>
#define ll long long

ll arr[100010];
ll fact[10000010];
ll fact2[10000010];

int main() {
    ll i, j, n, mod;
    scanf("%lld %lld", &n, &mod);

    for (i = 1; i <= n; ++i){
	scanf("%lld", arr + i);
    }

    fact[0] = 1;
    for (i = 1; i <= mod; ++i) {
	fact[i] = (fact[i-1] * i)%mod;
    }

    for (i = 1; i <= mod; ++i) {
	fact2[i] = (fact2[i-1] + (i * fact[i]) % mod)%mod;
    }

    ll sum = 0;
    for (i = 1; i <= n; ++i){
	ll x = arr[i];
	ll y, z;
	if (x%2 != 0) {
		z = ((x%mod)*(x%mod))%mod;
		y = (x+1)/2; y %= mod;
		sum = (sum + ((y * z)%mod))%mod;
	} else {
		z = (x+1)%mod;
		y = x/2; y %= mod; y = ((x%mod) * y)%mod;
		sum = (sum + ((y * z)%mod))%mod;
	}

	if(x >= mod) {
	    sum = (sum + (fact2[mod]%mod))%mod;
	} else {
	    sum = (sum + (fact2[x]%mod))%mod;
	}
    }
    printf("%lld\n",sum);
    return 0;
}
