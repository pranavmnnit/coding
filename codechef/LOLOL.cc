#include <iostream>
#include <cstring>
#include <vector>
#define min(a, b) ((a)>(b)?(b):(a))
using namespace std;

int main() {
    int t;
    string s;
    cin >> t;
    while (t--) {
	cin >> s;
	long long ans=0;
	int sz = static_cast<int>(s.size());
	vector<long long> vec;
	int i=0; int cnt=0;
	bool found=false;
	while (i<sz) {
	    if (s[i] == 'L') {
		found = true;
		vec.push_back(cnt);
		cnt = 0;
	    } else if (found && s[i] == 'O') {
		++cnt;
	    }
	    ++i;
	}
	i=1;
	for (vector<long long>::iterator it=vec.begin()+1; it!=vec.end(); ++it, ++i) {
	    *it = i**it + *(it-1);
	    ans+=*it;
	}
	cout << ans << endl;
    }
    return 0;
}
