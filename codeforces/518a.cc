#include <iostream>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    int sz = s.size();
    int c = 1, nc = 1;
    for (int i = sz-1; i >=0 ; --i) {
	nc = ((s[i]-'a'+c) >= 26 ) ? 1 : 0;
	s[i] = ((s[i]-'a'+c)%26)+'a';
	c = nc;
    }
    if (s < t) {
	cout << s << endl;
    } else {
	cout << "No such string" << endl;
    }
    return 0;
}
