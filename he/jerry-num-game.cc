#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int T;
    long N, m1, m2;
    bool arr[1000010];
    cin >> T;
    while (T--) {
	cin >> N >> m1 >> m2;
	memset(arr, 0, sizeof(arr[0])*(N+1));
	if (m1<=N) arr[m1] = 1;
	if (m2<=N) arr[m2] = 1;
	for (int i=(m1<m2)?(m1+1):(m2+1); i<=N; ++i) {
	    if (i-m1 >= 0 && !arr[i-m1]) {
		arr[i] = 1;
	    }
	    if (i-m2 >= 0 && !arr[i-m2]) {
		arr[i] = 1;
	    }
	}
	cout << arr[N] << endl;
    }
    return 0;
}
