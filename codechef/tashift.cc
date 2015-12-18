#include <iostream>
#include <string>
#include <vector>
#include <map>
#define tr(obj, it) \
    for ((typeof obj.begin()) it = obj.begin(); it != obj.end(); ++it)
using namespace std;

void failure(string &str, int sz, int* fail) {
    for (int i = 2; i < sz; ++i) {
	int t = fail[i-1];
	while(1) {
	    if (str[i-1] == str[t]) {
		fail[i] = fail[i-1]+1;
		break;
	    }
	    if (t == 0) {
		fail[i] = 0;
		break;
	    }
	    t = fail[t];
	}
    }
}

int main() {
    string str, pat;
    int fail[1000001] = {0};
    char ch;
    int N, i=0, j=0, m=0, idx=0;
    cin >> N;
    cin >> pat;
    cin >> str;
    str.append(str);
    failure(pat, N, fail);
    while(1) {
	if (i == N || j == 2*N) break; //whole match or str over
	if (pat[i] == str[j]) {
	    ++i; ++j;
	    m=i>m?i:m;
	    continue;
	}
	if (i == 0) { ++j;}
	i = fail[i];
    }

    if (m == 0) {
	cout << -1 << endl;
    } else {
	cout << str.find(pat.substr(0,m), 0) << endl;
    }
    return 0;
}
