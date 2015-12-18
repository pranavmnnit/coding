#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int t;
    int c1[26];
    int c2[26];
    string s1, s2;
    cin >> t;
    while (t--) {
	cin >> s1 >> s2;
	memset(c1, 0, sizeof(c1)); memset(c2, 0, sizeof(c2));
	if (s1.size() != s2.size()) {
	    cout << "NO" << endl;
	    continue;
	}
	for (int i=0; i < static_cast<int>(s1.size()); ++i) {
	    c1[s1[i]-'a']++;
	}
	for (int i=0; i < static_cast<int>(s2.size()); ++i) {
	    c1[s2[i]-'a']--;
	}
	bool flag=0;
	for (int i=0; i<26; ++i) {
	    if (c1[i]!=0) {
		cout << "NO" << endl;
		flag=1; break;
	    }
	}
	if (!flag) cout << "YES" << endl;
    }
    return 0;
}
