#include <iostream>
using namespace std;

int main() {
    int t, x, y, k, n, p, c;
    bool flag;
    scanf("%d", &t);
    while (t--) {
	flag = false;
	scanf("%d %d %d %d", &x, &y, &k, &n);
	for (int i = 0; i < n; ++i) {
	    scanf("%d %d", &p, &c);
	    if (p >= x - y && c <= k) flag = true;
	}
	if (flag) printf("LuckyChef\n");
	else printf("UnluckyChef\n");
    }
    return 0;
}
