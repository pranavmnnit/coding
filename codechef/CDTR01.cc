#include <iostream>
using namespace std;

int main() {
    int N, K, total;
    int arr[101], idx;
    int T;
    cin >> T;
    while (T--) {
	total = 0;
	cin >> N;
	for (int i=0; i<N; ++i) {
	    cin >> arr[i];
	}
	cin >> K;
	for (int i=0; i<K; ++i) {
	    cin >> idx;
	    idx--;
	    total += (arr[idx]<2000?arr[idx]:2000);
	}
	cout << total << endl;
    }
    return 0;
}
