#include <stdio.h>
#include <string.h>
#define LL long long

ll tree[10010];

int main() {
    LL t, n, q, a, b, val;
    scanf("%ld", &t);
    while(t--) {
	scanf("%ld %ld", &n, &q);
      	memset(tree, 0, sizeof(tree));
	while (q--) {
	    scanf("%ld %ld %ld", &a, &b, &val);
	    tree[a]+=val;
	    tree[b+1]-=val;
	}
	int i;
	for (i=1; i<n; ++i) {
	    tree[i]+=tree[i-1];
	}
	scanf("%ld", &q);
	while (q--) {
	    scanf("%ld", &a);
	    printf("%ld\n", tree[a]);
	}
    }
    return 0;
}
