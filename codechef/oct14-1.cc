#include <iostream>
using namespace std;

int main() {
    int T, M, N, arr[10010];
    int ma = -1, d=0;
    cin >> T;
    while (T--) {
	d = 0; ma = -1;
	cin >> N >> M;
	for (int i=0; i<N; ++i) {
	    cin >> arr[i];
	    if (arr[i] > ma) ma = arr[i];
	}
	for (int i=0; i<N; ++i) {
	    if (arr[i] < ma) {
		d += (ma-arr[i]);
	    }
	}
	if ((M>=d) && (M-d)%N==0) {
	    cout << "Yes" << endl;
	} else {
	    cout << "No" << endl;
	}
    }
    return 0;
}
