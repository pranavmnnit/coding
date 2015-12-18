#include <iostream>
using namespace std;

long long arr[1001][1001];

int main() {
    long long m, n, p, x, y;
    scanf("%lld %lld %lld", &m, &n, &p);
    for (long long i=1; i<=m; ++i) {
	for (long long j=1; j<=n; ++j) {
	    arr[i][j]=1;
	}
    }
    while (p--) {
	scanf("%lld %lld", &x, &y);
	arr[x][y]=-1;
    }
    for (long long i=2; i<=m; ++i) {
	if (arr[i-1][1]==-1) arr[i][1]=-1;
    }
    for (long long i=2; i<=n; ++i) {
	if (arr[1][i-1]==-1) arr[1][i]=-1;
    }
    for (long long i=2; i<=m; ++i) {
	for (long long j=2; j<=n; ++j) {
	    if (arr[i][j]>-1) {
		if ((arr[i-1][j]>-1) && (arr[i][j-1]>-1)) { arr[i][j]=arr[i-1][j]+arr[i][j-1]; arr[i][j]%=1000000007; }
		else if (arr[i-1][j]>-1) arr[i][j]=arr[i-1][j];
		else if (arr[i][j-1]>-1) arr[i][j]=arr[i][j-1];
		else arr[i][j]=-1;
	    }
	}
    }
    printf("%lld\n", (arr[m][n]>-1)?arr[m][n]:0);
    return 0;
}
