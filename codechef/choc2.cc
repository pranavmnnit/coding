#include <iostream>
#include <cstring>
#define ll long long
using namespace std;

ll tree[10010];
ll arr[10010];

void create(ll* arr, ll sz) {
    tree[0]=0;
    for (ll i=1; i<=sz; ++i) {
	ll upto=i&(i-1);
	tree[i]=arr[i]; ll idx=i-1;
	while (idx>upto) {
	    tree[i]+=tree[idx];
	    idx-=(idx&-idx);
	}
    }
}

int main() {
    ll t, n, q, a, b, val;
    scanf("%ld", &t);
    while(t--) {
	scanf("%ld %ld", &n, &q);
	memset(arr, 0, 10010);
	memset(tree, 0, 10010);
	while (q--) {
	    scanf("%ld %ld %ld", &a, &b, &val);
	    ++a; ++b;
	    while (a<=n) {
		tree[a]+=val;
		a+=(a&-a);
	    }
	    ++b;
	    while (b<=n) {
		tree[b]-=val;
		b+=(b&-b);
	    }
	}
	scanf("%ld", &q);
	while (q--) {
	    ll sum=0;
	    scanf("%ld", &a);
	    ++a;
	    while (a>0) {
		sum+=tree[a];
		a-=(a&-a);
	    }
	    cout << sum << endl;
	}
    }
    return 0;
}
