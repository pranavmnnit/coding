#include <iostream>
using namespace std;

int main() {
    int T, N, B[10010];
    int sum;
    cin >> T;
    while (T--) {
	int subtract;
	cin >> N;
	sum=0;
	for (int i=0; i<N; ++i) {
	    cin >> B[i];
	    sum += B[i];
	    if(B[i]==0)
	    subtract++;
	}
	if (sum>=100 && sum<100+N-subtract) {
	    cout << "YES" << endl;
	} else {
	    cout << "NO" << endl;
	}
    }
    return 0;
}
