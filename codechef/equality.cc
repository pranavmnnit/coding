#include <iostream>
#define ll long long
using namespace std;

ll arr[100010];

int main() {
    int t;
    ll n, sum;
    cin >> t;
    while (t--) {
	sum = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
	    cin >> arr[i];
	    sum += arr[i];
	}
	sum /= (n-1);
	for (int i = 0; i < n; ++i) {
	    cout << sum - arr[i] << " ";
	}
	cout << endl;
    }
    return 0;
}
