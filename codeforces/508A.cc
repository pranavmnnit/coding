#include <iostream>
using namespace std;

int a[1001][1001];

int main() {
    int n, m, k;
    int i, j, p;
    cin >> n >> m >> k;
    for (p=1; p<=k; ++p) {
	cin >> i >> j;
	a[i][j]=1;
	if (i>1 && j>1) {
	    if (a[i-1][j] && a[i][j-1] && a[i-1][j-1]) break;
	} if (i>1 && j<m) {
	    if (a[i][j+1] && a[i-1][j] && a[i-1][j+1]) break;
	} if (i<n && j>1) {
	    if (a[i+1][j-1] && a[i+1][j] && a[i][j-1]) break;
	} if (i<n && j<m) {
	    if (a[i+1][j] && a[i+1][j+1] && a[i][j+1]) break;
	}
    }
    if (p<=k) cout << p << endl;
    else cout << 0 << endl;
    return 0;
}
