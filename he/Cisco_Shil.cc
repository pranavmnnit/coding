#include <iostream>
using namespace std;

int main() {
    int n, a, sz;
    bool num[1000010] = {0};
    scanf("%d", &n);
    while (n--) {
	scanf("%d", &a);
	if (!num[a]) {
	    num[a] = true;
	    ++sz;
	}
    }
    printf("%lld\n", (1LL * sz * (sz-1))/(1LL * 2));
    return 0;
}
