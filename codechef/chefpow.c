#include <stdio.h>
int main() {
    long long N, cnt=0;
    scanf("%lld", &N);
    while (N) {
	if(N&1) printf("%lld ", (1<<cnt));
	++cnt; N >>= 1;
    }
    printf("\n");
    return 0;
}
