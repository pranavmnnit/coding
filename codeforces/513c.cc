#include <iostream>
using namespace std;

int main() {
    int n;
    int l[5], r[5];
    scanf("%d", &n);
    for (int i=0; i<n; ++i) {
	scanf("%d %d", l+i, r+i);
    }
    for (int i=0; i<n; ++i) {
	bool flag=1; int ma=-1;
	for (int j=0; j<n; ++j) {
	    if (i==j) continue;
	    if (r[i]<l[j]) {
		flag=0; break;
	    } else {
		if (l[j]>ma) ma=l[j];
	    }
	}
	if (flag==1) {
	    //ma to r[i]

	}
    }
