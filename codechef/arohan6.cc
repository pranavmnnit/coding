#include <iostream>
using namespace std;

int main() {
    long long n, l ,r;
    scanf("%llu", &n);
    while (n--) {
	scanf("%llu %llu", &l, &r);
	long long lset=-1, rset=-1;
	long long l2=l, r2=r;
	while (l2) { l2 >>= 1; ++lset; } while (r2) { r2 >>= 1; ++rset; }
	if (!l && !r) { cout << 0 << endl; continue; }
	if (!l) {
	    if (r==(1<<(rset+1)-1)) { cout << r << endl; }
	    else { cout << ((1<<rset)-1) << endl; continue; }
	} else {
	    if (rset>lset) {
		if (r==(1<<(1+rset)-1)) { cout << r << endl; continue; }
		else { cout << ((1<<rset)-1) << endl; continue; }
	    } else {
		while ((l & (1<<lset)) && (r & (1<<rset))) { --lset; --rset; }
		while (--lset) l |= (1<<lset);
		cout << l << endl;
	    }
	}
    }
    return 0;
}
