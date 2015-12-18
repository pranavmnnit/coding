#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#define tr(obj, it) for(typeof((obj).begin()) it = (obj).begin(); it != (obj).end(); ++it)
using namespace std;

int main() {
    int n;
    string str;
    set<string> S;
    cin >> n;
    for (int i = 0; i < n; ++i) {
	cin >> str;
	S.insert(str);
    }
    if (S.size() != n) {
	cout << "vulnerable\n";
    } else {
	set<string>::iterator it = S.begin(); ++it;
	while (it != S.end()) {
	    set<string>::iterator it2 = it;
	    --it2;
	    if ((*it).find(*it2) != string::npos) {
		cout << "vulnerable\n";
		return 0;
	    }
	    ++it;
	}
	cout << "non vulnerable\n";
	return 0;
    }
    return 0;
}
