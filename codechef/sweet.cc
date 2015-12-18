#include <iostream>
#define ull long long
using namespace std;

int main() {
    ull t, n, x;
    ull max=0, max_so_far=0;
    ull a;
    cin >> t;
    while (t--) {
	max=max_so_far=0;
	cin >> n >> x;
	for (ull i=0; i<n; ++i) {
	    cin >> a;
	    a-=x;
	    if (max_so_far+a>0) {
		max_so_far=max_so_far+a;
		max=(max_so_far>max?max_so_far:max);
	    } else {
		max_so_far=0;
	    }
	}
	cout << max << endl;
    }
    return 0;
}
