#include <iostream>
#include <algorithm>
#define ull unsigned long long
using namespace std;

ull h[1001];

int main() {
    ull n, k;
    cin >> n >> k;
    for (ull i=0; i<n; ++i) {
	cin >> h[i];
    }
    sort(h, h+n);
    ull s=0, e=n-1;
    while (s<e) {
	if (h[s]+h[e]==k) { cout << "Yes" << endl; break; }
	else if (h[s]+h[e]<k) s++;
	else e--;
    }
    if (s==e) cout << "No" << endl;
    return 0;
}
