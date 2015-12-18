#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T, N;
    int arr[1010];
    cin >> T;
    while (T--) {
	cin >> N;
	for (int i=0; i<N; ++i) {
	    cin >> arr[i];
	}
	sort(arr, arr+N, std::greater<int>());
	int cost=0;
	for (int i=0; i<N; i+=4) {
	    cost+=arr[i]+((i+1)<N?arr[i+1]:0);
	}
	printf("%d\n", cost);
    }
    return 0;
}
