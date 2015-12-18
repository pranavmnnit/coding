#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int t;
    string str;
    cin >> t;
    while (t--) {
	cin >> str;
	int sz=str.size();
	int s, e, ma=0;
	bool seen[27]={false};
	s=0; e=1;
	while (e<sz) {
	    seen[str[s]-'A']=true;
	    while (e<sz && !seen[str[e]-'A']) { seen[str[e]-'A']=true; ++e; }
	    if (e-s>ma) ma=e-s;
	    s++; e=s+1; memset(seen, 0, sizeof(seen));
	}
	cout << ma << endl;
    }
    return 0;
}
