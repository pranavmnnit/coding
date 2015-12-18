#include <iostream>
using namespace std;

string a[51];

int istrue(int i, int j, int k, int l) {
    cout << "called with i=" << i << ", j=" << j << ", k=" << k << ", l=" << l << endl;
    char ch=a[i][j];
    for (int s=i; s<=k; ++s) {
	if (a[s][j]!=ch) { cout << ">> not found 1" << endl; return 0; }
    }
    for (int s=i; s<=k; ++s) {
	if (a[s][l]!=ch) { cout << ">> not found 2" << endl; return 0; }
    }
    for (int s=j; s<=l; ++s) {
	if (a[i][s]!=ch) { cout << ">> not found 3" << endl; return 0; }
    }
    for (int s=j; s<=l; ++s) {
	if (a[k][s]!=ch) { cout << ">> not found 4" << endl; return 0; }
    }
    return 1;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; ++i) {
	    cin >> a[i];
    }

    for (int i=0; i<n-1; ++i) {
	for (int j=0; j<m-1; ++j) {
	    for (int k=i+1; k<n; ++k) {
		for (int l=j+1; l<m; ++l) {
		    if (istrue(i, j, k, l)) {
			cout << "Yes" << endl; return 0;
		    }
		}
	    }
	}
    }
    cout << "No" << endl;
    return 0;
}
