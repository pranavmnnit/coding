#include <iostream>
using namespace std;

int main() {
    int t, q, i, j, k, s, e, idx, n;
    string s1, s2;
    cin >> t;
    while (t--) {
	cin >> s1;
	cin >> s2;
	cin >> q;
	while (q--) {
	    cin >> i >> j >> k;
	    --i; --j;
	    int arr1[26] = {0}; int arr2[26] = {0};
	    int Arr1[i+k], Arr2[i+k];
	    idx = 1;
	    int sz1 = static_cast<int>(s1.size());
	    int sz2 = static_cast<int>(s2.size());
	    for (s = i, n = 0; s < i+k; ++s, ++n) {
		arr1[s1[s] - 'a'] = (arr1[s1[s] - 'a'] == 0) ? (idx++) : arr1[s1[s] - 'a'];
		Arr1[n] = arr1[s1[s] - 'a'];
	    }
	    idx = 1;
	    for (s = i, n = 0; s < i+k; ++s, ++n) {
		arr2[s2[s] - 'a'] = (arr2[s2[s] - 'a'] == 0) ? (idx++) : arr2[s2[s] - 'a'];
		Arr2[n] = arr2[s2[s] - 'a'];
	    }
	    bool flag = true;
	    for (s = 0; s < k; ++s) {
		if (Arr1[s] != Arr2[s]) {
		    flag = false; break;
		}
	    }
	    cout << (flag ? "yes" : "no") << endl;
	}
    }
    return 0;
}
