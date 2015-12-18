#include<iostream>
#include<map>
#include<vector>
using namespace std;

int main()
{
    long testCount;
    long a;
    long rootdeg = 1;
    long tc = 0, tno = 0;
    long p1, p2, M, N;
    long ttt = 0;

    cin >> testCount;
    ttt = testCount;
    map <long,long> toParent;
    long ans[100][2000];
    int tno2[100];

    while (testCount--) {
	toParent.erase(toParent.begin(), toParent.end());
	rootdeg = 1;
	toParent[rootdeg] = 1;
	cin >> N >> M;
	tno2[tc] = M;
	N -= 1;
	while (N--) {
	    cin >> p1 >> p2;
	    if (p1 != 1) {
		toParent[p2] = toParent[p1];
	    } else {
		toParent[p2] = ++rootdeg;
	    }
	}
	while (M--) {
	    cin >> p1 >> p2;
	    if ((toParent[p1] == toParent[p2])) {
		ans[tc][tno] = 1;
	    } else if ((p1 == 1) && (toParent[toParent[p2]] == toParent[p2])) {
		ans[tc][tno] = 1;
	    } else if ((p2 == 1) && (toParent[toParent[p1]] == toParent[p1])) {
		ans[tc][tno] = 1;
	    } else {
		ans[tc][tno] = 0;
	    }
	    tno++;
	}
	tc++;
	tno = 0;
    }
    for (long i=0; i<ttt; i++) {
	cout << "Case #" << (i+1) << "\n";
	for (long j=0; j<tno2[i]; j++) {
	    cout << ans[i][j] << "\n";
	}
    }
    return 0;
}
