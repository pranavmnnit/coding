#include <iostream>
#define ll long long
using namespace std;

int main() {
    ll t, n, s, i, cur;
    cin >> t;
    while (t--) {
	cin >> n >> s;
	i = 1;
	cur = n;
	while (s >= cur) cur += (i++);
	cout << n-i+1 << endl;
    }
    return 0;
}
