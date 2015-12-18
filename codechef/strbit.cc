#include <iostream>
#define MIN(a, b) ((a) < (b) ? (a) : (b))
using namespace std;

int main() {
    string str;
    int t, sz, k, ans;
    cin >> t;
    while (t--) {
	int cnt[100010] = {0};
	ans = 0;
	cin >> sz >> k;
	cin >> str;
	for (int i = 0; i < sz; ++i) {
	    cnt[i] = cnt[i] + ((i > 0) ? cnt[i-1] : 0);
	    if ((str[i] == 'G' && cnt[i]%2 == 0) || (str[i] == 'R' && cnt[i]%2 == 1)) continue;
	    else {
		++ans;
		cnt[i] = cnt[i] + 1;
		cnt[MIN(sz, i+k)] = cnt[MIN(sz, i+k)] - 1;
	    }
	}
	cout << ans << endl;
    }
    return 0;
}
