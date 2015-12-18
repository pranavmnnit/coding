#include <iostream>
#include <cstring>
using namespace std;

void print(int* a) {
    for (int i=0; i<26; ++i) {
	cout << a[i] << " ";
    }
    cout << endl;
}

inline bool comp(int* a, int* b) {
    for (int i=0; i<26; ++i) {
	if (a[i] != b[i]) return false;
    }
    return true;
}

int main()
{
    int T;
    string t, p;
    bool done = false;
    int cnt[26], temp[26], L, R;
    cin >> T;
    while (T--) {
    	done = false;
    	memset(cnt, 0, 26*sizeof(int));
    	memset(temp, 0, 26*sizeof(int));
    	cin >> p >> t;
    	int sz = p.size();
    	L = 0; R = sz-1;
    	for (int i=0; i<sz; ++i) {
	    ++cnt[p[i]-'a'];
	    if (i<t.size()) ++temp[t[i]-'a'];
    	}
    	if (comp(cnt, temp)) { cout << "YES" << endl; done = true; }
	//print(cnt);
	//print(temp);
    	if (done) continue;

    	int szt = t.size();
    	while (!done && (R<szt)) {
	    ++R;
	    --temp[t[L]-'a'];
	    ++temp[t[R]-'a'];
	    ++L;
	    //print(temp);
	    if (comp(cnt, temp))  { cout << "YES" << endl; done = true; }
    	}
	if (!done) {
	    cout << "NO" << endl;
	}
    }
    return 0;
}
