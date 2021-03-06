#include <iostream>
#include <cstring>
#include <set>
using namespace std;

int main() {
    int eater[21], eaten[21];
    set<int> S;
    int T, N, M, c, d, su, a, b;
    cin >> T;
    while (T--) {
	su=0;
	set<int> T;
	swap(S,T);
	memset(eater, 0, sizeof(eater));
	memset(eaten, 0, sizeof(eaten));
	cin >> N >> M;
	if (M==0 || M==1) {
	    if (M==1) { cin >> a >> b; }
	    cout << "YES" << endl;
	    continue;
	}
	for (int i=0; i<M; ++i) {
	    cin >> a >> b;
	    --a; --b;
	    eater[b]++;
	    eaten[a]++;
	}
	a=b=0;
	for (int i=0; i<N; ++i) {
	    su += eater[i]+eaten[i];
	    if (eater[i]) { S.insert(i); }
	    if (eaten[i]) { S.insert(i); }
	}
	cout << (((su<=4) && (S.size()<=3))?"YES":"NO") << endl;
    }
    return 0;
}
