#include <iostream>
using namespace std;

int main() {
    int t;
    string str;
    cin >> t;
    while (t--) {
	int cnt[27]={0};
	cin >> str;
	int sz=str.size();
	for (int i=0; i<sz; ++i) {
	    if (str[i]>='a') str[i]-='a';
	    cnt[str[i]-'A']++;
	}
	int ma=-1; char ch;
	for (int i=0; i<26; ++i) {
	    if (cnt[i]>ma) {
		ma = cnt[i];
		ch = i;
	    }
	}
	cout << ch+'A' << endl;
    }
    return 0;
}

