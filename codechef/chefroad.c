#include <stdio.h>

int to[1010][1010];
int idx[1010];

int DO(int n) {
    int i, j, k, l, m, cnt=0;
    for (i=1; i<=n; ++i) {
	for (j=0; j<idx[i]; ++j) {
	    for (k=j+1; k<idx[i]; ++k) {
		for (l=0; l<idx[to[i][j]]; ++l) {
		    for (m=0; m<idx[to[i][k]]; ++m) {
			if ((to[to[i][j]][l]==to[to[i][k]][m]) && (to[to[i][j]][l]!=i)) {
			    ++cnt;
			}
		    }
		}
	    }
	}
    }
    return cnt;
}

int main() {
    int n, m, conf;
    int a, b, i, j;
    scanf("%d %d", &n, &m);
    while (m--) {
	scanf("%d %d", &a, &b);
	to[a][idx[a]++]=b;
    }
    printf("%d\n", DO(n));
    return 0;
}
