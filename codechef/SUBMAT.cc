#include <iostream>
#define min(a,b,c) ((a<b)?((a<c)?a:c):((b<c)?b:c))
using namespace std;

int main() {
    int t, m, n, i, j, max;
    scanf("%d", &t);
    while (t--) {
	cin >> m >> n;
	max=0;
	int arr[101][101]={0};
	for (int i=0; i<m; ++i) {
	    for (int j=0; j<n; ++j) {
		scanf("%d", *(arr+i)+j);
		if (arr[i][j]) max=1;
	    }
	}
	for (int i=1; i<m; ++i) {
	    for (int j=1; j<n; ++j) {
		if (arr[i][j] && arr[i-1][j] && arr[i][j-1] && arr[i-1][j-1]) {
		    arr[i][j]=min(arr[i-1][j], arr[i-1][j-1], arr[i][j-1])+1;
		    max=(arr[i][j]>max?arr[i][j]:max);
		}
	    }
	}
	printf("%d\n", max);
    }
    return 0;
}
