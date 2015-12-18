#include <iostream>
using namespace std;

int main() {
    int T, M;
    bool flag=true;
    string s1, s2, map;
    bool arr[26][26];
    cin >> T;
    while (T--) {
	flag=true;
	for (int i=0; i<26; ++i) {
	    for (int j=0; j<26; ++j) {
		arr[i][j] = false;
	    }
	}
	cin >> s1 >> s2 >> M;
	for (int i=0; i<M; ++i) {
	    cin >> map;
	    arr[map[0]-'a'][map[3]-'a'] = true;
	}
	if (s1.size() != s2.size()) {
	    cout << "NO" << endl;
	    continue;
	}
	for (int i=0; i<26; ++i) {
	    for (int j=0; j<26; ++j) {
		for (int k=0; k<26; ++k) {
		    if (arr[j][i] && arr[i][k]) {
			arr[j][k] = true;
		    }
		}
	    }
	}
	int sz = s1.size();
	for (int i=0; i<sz; ++i) {
	    if ((s1[i] != s2[i]) && (arr[s1[i]-'a'][s2[i]-'a'] == false)) {
		flag = false;
		break;
	    }
	}
	cout << (flag?"YES":"NO") << endl;
    }
    return 0;
}
