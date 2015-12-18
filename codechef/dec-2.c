#include <stdio.h>

int main() {
    short T, N, K;
    short a;
    scanf("%d", &T);
    while (T--) {
        short ans[1024]={0};
        scanf("%d %d", &N, &K); ans[0]=1;
        int ma=K,i,j;
        for (i=0; i<N; ++i) {
            scanf("%d", &a);
            for (j=0; j<1024; ++j) {
                if (ans[j]) {ans[a^j]=1;
                ma=(a^j^K)>ma?(a^j^K):ma;}
            }
        }
        printf("%d\n", ma);
    }
    return 0;
}
