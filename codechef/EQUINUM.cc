#include <iostream>
#define ll long long
using namespace std;

int main() {
    int t, n, flag;
    cin >> t;
    while (t--) {
	cin >> n;
	flag=0;
	ll left[n+2], right[n+2], arr[n+2];
	for (ll i=0; i<n; ++i) {
	    cin >> arr[i];
	}
	left[0]=arr[0]; right[n-1]=arr[n-1];
	for (ll i=1; i<n; ++i) {
	    left[i]=left[i-1]+arr[i];
	    right[n-i-1]=right[n-i]+arr[n-i-1];
	}
	for (ll i=1; i<n-1; ++i) {
	    if (left[i-1]==right[i+1]) {
		cout << arr[i] << endl;
		flag=1;
		break;
	    }
	}
	if (!flag) {
	    cout << "NO EQUILIBRIUM" << endl;
	}
    }
    return 0;
}
