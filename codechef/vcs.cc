#include <iostream>
using namespace std;

int main() {
    int t;
    int x, n, m, k;
    int tr, ign;
    cin >> t;
    while (t--) {
	int arr[110] = {0};
	cin >> n >> m >> k;
	for (int i = 0; i < m; ++i) {
	    cin >> x;
	    arr[x]++;
	}
	for (int i = 0; i < k; ++i) {
	    cin >> x;
	    arr[x]++;
	}
	tr = ign = 0;
	for (int i = 1; i <= n; ++i) {
	    if (arr[i] == 0) ++ign;
	    if (arr[i] == 2) ++tr;
	}
	cout << tr << " " << ign << endl;
    }
    return 0;
}
