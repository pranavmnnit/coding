#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
    int t, n;
    int a;
    int m[100010];
    cin >> t;
    while (t--) {
	memset(m, 0, sizeof(m));
	cin >> n;
	int cnt=0;
	for (int i=0; i<n; ++i) {
	    cin >> a;
	    m[a]++;
	}
	sort(m, m+100010, std::greater<int>());
	for (int i=1; i<=100001; ++i) {
	    cnt+=m[i];
	}
	cout << cnt << endl;
    }
    return 0;
}
