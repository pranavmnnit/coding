#include <iostream>
#define min(a, b) ((a)<(b)?(a):(b))
using namespace std;

void Do(int** mat, int m) {
    for (int i = 1; i <= m; ++i) {
	for (int j = 1; j <= m; ++j) {
	    for (int k = 1; k <= m; ++k) {
		if (mat[j][i] && mat[i][k]) mat[j][k] = 1;
	    }
	}
    }
}

int cost(int* arr, int** mat, int sz, int m) {
    int cost = 0;
    arr[0] = -1;
    for (int i = 1; i <= sz; ++i) {
	if (arr[i] < arr[i-1]) {
	    bool flag = false;
	    for (int j = arr[i-1]; j <= m; ++j) {
		if (mat[arr[i]][j]) {
		    arr[i] = j;
		    flag = true;
		    ++cost;
		    break;
		}
	    }
	    if (!flag) return -1;
	}
    }
    return cost;
}

int main() {
    int t;
    int m, k, n, x, y;
    cin >> t;
    while (t--) {
	cin >> m >> k >> n;
	int** mat = new int*[m+1];
	for (int i = 0; i <= m; ++i) {
	    mat[i] = new int[m+1];
	}
	for (int i = 0; i < k; ++i) {
	    cin >> x >> y;
	    mat[x][y] = mat[y][x] = 1;
	}
	Do(mat, m);
	int *arr = new int[n+1];
	for (int i = 1; i <= n; ++i) {
	    cin >> arr[i];
	}
	cout << cost(arr, mat, n, m) << endl;
    }
    return 0;
}
