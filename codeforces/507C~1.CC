#include <iostream>
#define ull unsigned long long
using namespace std;

inline ull lca(ull n1, ull n2) {
    while (n1!=n2) {
	n1>>=1; n2>>=1;
    }
    return n1;
}

void DO(ull curh, ull h, ull curn, ull node, int left, ull &cnt) {
    ull upto = 0;
    do {
	//cout << ">curh= " << curh << ", h= " << h << ", curn= " << curn << ", node= " << node << ", left= " << left << endl;
	//sleep(1);
	if (left==1) {
	    curn=curn*2;
	} else {
	    curn=curn*2+1;
	}
	++curh; ++upto;
	cout << ">>upto= " << upto << ", curh= " << curh << ", curn= " << curn << ", left= " << left << endl;
	sleep(1);
	if (curh==h && curn==node) { cnt=cnt+upto; return; }
	else if (curh==h) {
	    ull L=lca(curn, node);
	    ull L2=L;
	    ull H=0;
	    while (L2>1) {
		L2>>=1; ++H;
		//cout << "now L2= " << L2 << endl;
	    }
	    cnt=upto+(1<<(h-H))-h+H-1;
	    cout << ">>>lca= " << L << ", H= " << H << "cnt= " << cnt << ", upto= " << upto << ", left= " << left << endl;
	    sleep(1);
	    if ((curh%2)==0) {
		//cout << "Even" << endl;
		left=(node>curn?left:-left);
	    }
	    else {
		//cout << "Odd" << endl;
		left=(node<curn)?left:-left;
	    }
	    curh=H; curn=L;
	    upto=0;
	} else {
	    left=-left;
	}
    } while (curh<h);
}

int main() {
    ull h, n;
    cin >> h >> n;
    ull cnt=0;
    DO(0, h, 1, (1<<h)-1+n, 1, cnt);
    cout << cnt << endl;
    return 0;
}
