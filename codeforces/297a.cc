#include <iostream>
using namespace std;

int main() {
    long cnt[28] = {0};
    long n, ans = 0;
    string str;

    cin >> n;
    cin >> str;

    for (long i = 0; i < (2*n - 2); i += 2) {
	cnt[str[i] - 'a']++;
	if (cnt[str[i+1] - 'A']) {
	    --cnt[str[i+1] - 'A'];
	} else {
	    ++ans;
	}
    }
    cout << ans << endl;
    return 0;
}
