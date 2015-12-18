#include <stdio.h>
#define N0(a) (((a)*(a+1))/2)
#define N1(a) (((a)*(a-1))/2)
#define N2(a) (((a)*(a-1))/2)
#define NUM(ch) (((ch-'0')%3))
#define ull unsigned long long

int main() {
    ull N, sum[100010];
    ull cnt[100010][3];
    ull M, T, X, Y;
    char str[100010];
    scanf("%llu %llu", &N, &M);
    scanf("%s", str);

    sum[0]=0;
    ull i;
    for (i=1; i<=N; ++i) {
        sum[i]=(sum[i-1]+NUM(str[i-1]))%3;
        cnt[i][0]=cnt[i-1][0]; cnt[i][1]=cnt[i-1][1]; cnt[i][2]=cnt[i-1][2];
        cnt[i][sum[i]]=cnt[i-1][sum[i]]+1;
    }
    for (i=0; i<M; ++i) {
        scanf("%llu %llu %llu", &T, &X, &Y);
        if (T == 1) {
            ull j;
            ull dif=(NUM(str[X-1])-(Y%3)+3)%3;
            if (dif) {
                for (j=X; j<=N; ++j) {
                    sum[j]=(sum[j]-dif+3)%3;
                    cnt[j][0]=cnt[j-1][0]; cnt[j][1]=cnt[j-1][1]; cnt[j][2]=cnt[j-1][2];
                    cnt[j][sum[j]]=cnt[j-1][sum[j]]+1;
                }
            }
            str[X-1]=Y+'0';
        } else if (T == 2) {
            ull cnt1=0,cnt2=0,cnt0=0;
            cnt0=cnt[Y][0]-cnt[X-1][0]; cnt1=cnt[Y][1]-cnt[X-1][1]; cnt2=cnt[Y][2]-cnt[X-1][2];
            //printf("%d\t%d\t%d\n", cnt[15][0], cnt[15][1], cnt[15][2]);
            ull d = (sum[X]-NUM(str[X-1])+3)%3;
            while(d--) cnt2=cnt0^cnt1^cnt2^(cnt0=cnt1)^(cnt1=cnt2);
            printf("%llu\n", N0(cnt0)+N1(cnt1)+N2(cnt2));
        }
    }
    return 0;
}
