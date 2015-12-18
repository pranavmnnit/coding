#include <iostream>
using namespace std;

int main() {
    int T, N, M, i, j;
    int p[1010][1010];
    for (int i=1; i<=1000; ++i) {
	p[i][1]=p[1][i]=i;
    }
    for (i=2; i<=1000; ++i) {
	for (j=2; j<=1000; ++j) {
	    p[i][j]=p[i-1][j]+p[i][j-1]-p[i-1][j-1];
	}
    }
    cin >> T;
    while (T--) {
	cin >> N >> M;
	cout << p[N][M] << endl;
    }
    return 0;
}
