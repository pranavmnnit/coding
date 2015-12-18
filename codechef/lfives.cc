#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;

ll dp[2010][2010];
ll W[2010][2010];
ll arr[2010];

void Do(int n) {
    int i, j, k;
    for (i = 1; i <= n; ++i) {
	for (j = i+2; j <= n; ++j) {
	    for (k = i+1; k < j; ++k) {
		if (arr[k] < arr[i] && arr[k] < arr[j]) ++dp[i][j];
	    }
	}
    }

    for (i = 1; i <= n; ++i) {
	for (j = i+2; j <= n; ++j) {
	    for (k = i+1; k < j; ++k) W[i][j] += (dp[i][k] * dp[k][j]);
	}
    }
}

int main() {
    int n, q, l, r;
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; ++i) {
	scanf("%lld", arr+i);
    }
    Do(n);
    for (int i = 0; i < q; ++i) {
	scanf("%d %d", &l, &r);
	printf("%lld\n", W[l][r]);
    }
    return 0;
}
