#include <iostream>
using namespace std;

int main() {
    int cnt=0, total=0;
    total=80;
    int wc=0;
    int i, j;
    for (i=1; i<=9; ++i) {
	if (total==1) break;
	for (j=1; j<=9; ++j) {
	    if (wc==59) goto next;
	    ++cnt;
	    if (cnt<=total) {
		cout << i << " " << j << endl;
		if (cnt!=total) cout << "0 0" << endl;
	    }
	    else {
		wc++;
		cout << i << " " << j  << endl;
		--total; cnt=0;
		i=0;
		break;
	    }
	}
    }
next:
    total=18; wc=0;
    cout << "1 2" << endl; cout << "0 0" << endl;
    cout << "2 1" << endl;
    j=4; i=3;
    for (; i>=1; --i) {
	if (j!=4) j=9;
	for (; j>=1; --j) {
	    if (i==2 && j==1) continue;
	    if (wc==total) goto next2;
	    cout << i << " " << j << endl;
	    wc++;
	    if (wc!=total) cout << "0 0" << endl;
	}
    }
next2:
    //cout << "....next set...." << endl;
    total=77;
    cout << "1 3" << endl; //p1
    while(1) {
	cout << "....next round...." << endl;
	wc=0; --total;
	if (total == 30) break;
	for (i=9; i>=1; --i) {
	    for (j=9; j>=1; --j) {
		if (i==2 && j==1) continue;
		cout << i << " " << j << endl; //p2
		wc++;
		if (wc!=total) {
		    cout << "0 0" << endl; //p1
		} else {
		    if (j==1) cout << i-1 << " 9" << endl;
		    else cout << i << " " << j-1 << endl;
		    i=1; break;
		}
	    }
	}
    }
    return 0;
}
