#include <iostream>
#include <cstring>
#define N0(a) (((a)*(a+1))/2)
#define N1(a) (((a)*(a-1))/2)
#define N2(a) (((a)*(a-1))/2)
#define NUM(ch) (((ch-'0')%3))
#define ull unsigned long long
using namespace std;

int main() {
    ull N, sum[100010];
    ull cnt[100010][3];
    memset(cnt, 0, 100010*3*sizeof(ull));
    memset(sum, 0, 100010*sizeof(ull));
    ull M, T, X, Y;
    string str;
    scanf("%llu %llu", &N, &M);
    cin >> str;

    sum[0]=0;
    for (ull i=1; i<=N; ++i) {
	sum[i]=(sum[i-1]+NUM(str[i-1]))%3;
	cnt[i][0]=cnt[i-1][0]; cnt[i][1]=cnt[i-1][1]; cnt[i][2]=cnt[i-1][2];
	cnt[i][sum[i]]=cnt[i-1][sum[i]]+1;
    }
    for (ull i=0; i<M; ++i) {
	scanf("%llu %llu %llu", &T, &X, &Y);
	if (T == 1) {
	    ull i;
	    ull dif=(NUM(str[X-1])-(Y%3)+3)%3;
	    if (dif) {
		for (i=X; i<=N; ++i) {
		    sum[i]=(sum[i]-dif+3)%3;
		    cnt[i][0]=cnt[i-1][0]; cnt[i][1]=cnt[i-1][1]; cnt[i][2]=cnt[i-1][2];
		    cnt[i][sum[i]]=cnt[i-1][sum[i]]+1;
		}
	    }
	    str[X-1]=Y+'0';
	} else if (T == 2) {
	    ull cnt1=0,cnt2=0,cnt0=0;
	    cnt0=cnt[Y][0]-cnt[X-1][0]; cnt1=cnt[Y][1]-cnt[X-1][1]; cnt2=cnt[Y][2]-cnt[X-1][2];
	    ull d = (sum[X]-NUM(str[X-1])+3)%3;
	    while(d--) cnt2=cnt0^cnt1^cnt2^(cnt0=cnt1)^(cnt1=cnt2);
	    printf("%llu\n", N0(cnt0)+N1(cnt1)+N2(cnt2));
	}
    }
    return 0;
}
