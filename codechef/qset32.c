#include <stdio.h>
#include <string.h>
#define N0(a) (((a)*(a+1))/2)
#define N1(a) (((a)*(a-1))/2)
#define N2(a) (((a)*(a-1))/2)
#define NUM(ch) (((ch-'0')%3))
#define ull unsigned long long

int main() {
    ull N, sum[100010];
    ull cnt[100010][3];
    ull M, T, X, Y;
    ull ToDo=0;
    ull todo[100010]={0};
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
	    ull dif=(NUM(str[X-1])-(Y%3)+3)%3;
	    todo[X]=(todo[X]-dif)%3;
	    if (ToDo && X<ToDo) ToDo=X;
	    else if (!ToDo) ToDo=X;
            str[X-1]=Y+'0';
        } else if (T == 2) {
	    ull j;
	    if (ToDo && Y>=ToDo) {
		for (j=ToDo; j<=N; ++j) {
		    sum[j]=(sum[j]-todo[j]+3)%3;
		    cnt[j][0]=cnt[j-1][0]; cnt[j][1]=cnt[j-1][1]; cnt[j][2]=cnt[j-1][2];
		    cnt[j][sum[j]]=cnt[j-1][sum[j]]+1;
		}
		memset(todo, 0, 100010*sizeof(ull));
		ToDo=0;
	    }
            ull cnt1=0,cnt2=0,cnt0=0;
            cnt0=cnt[Y][0]-cnt[X-1][0]; cnt1=cnt[Y][1]-cnt[X-1][1]; cnt2=cnt[Y][2]-cnt[X-1][2];
            ull d = (sum[X]-NUM(str[X-1])+3)%3;
            while(d--) cnt2=cnt0^cnt1^cnt2^(cnt0=cnt1)^(cnt1=cnt2);
            printf("%llu\n", N0(cnt0)+N1(cnt1)+N2(cnt2));
        }
    }
    return 0;
}
