#include <iostream>
#include <cstring>
#define ll long long
using namespace std;

int main() {
    ll t, n, q, a, b, val;
    scanf("%ld", &t);
    while(t--) {
	scanf("%ld %ld", &n, &q);
	ll arr[n+1]; memset(arr, 0, sizeof(arr));
      	ll tree[n+1]; memset(tree, 0, sizeof(tree));
	while (q--) {
	    scanf("%ld %ld %ld", &a, &b, &val);
	    tree[a+1]+=val;
	    tree[b+2]-=val;
	}
	for (ll i=1; i<=n; ++i) {
	    tree[i]+=tree[i-1];
	}
	scanf("%ld", &q);
	while (q--) {
	    scanf("%ld", &a);
	    cout << tree[a+1] << endl;
	}
    }
    return 0;
}
