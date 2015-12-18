#include <iostream>
using namespace std;

int main() {
    string str;
    bool arr[26];
    int dc;
    int T;
    cin >> T;
    while (T--) {
	dc = 0;
	for(int i=0; i<26; ++i) arr[i] = false;
	cin >> str;
	int sz = str.size();
	for (int i=0; i<sz; ++i) {
	    if (!arr[str[i]-'a']) {
		arr[str[i]-'a'] = true;
		dc++;
	    }
	}
	cout << dc << endl;
    }
    return 0;
}
