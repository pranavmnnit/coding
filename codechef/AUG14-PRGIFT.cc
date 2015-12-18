#include <iostream>
using namespace std;

int main() {
    int T, n, k, noe;
    int arr[101];
    cin >> T;
    while (T--) {
	cin >> n >> k;
	noe = 0;
	for (int i=0; i<n; i++) {
	    cin >> arr[i];
	    if (arr[i] % 2 == 0) noe++;
	}
	if (noe == n && k == 0) {
	    cout << "NO" << endl;
	} else if (noe >= k) {
	    cout << "YES" << endl;
	} else {
	    cout << "NO" << endl;
	}
    }
    return 0;
}
