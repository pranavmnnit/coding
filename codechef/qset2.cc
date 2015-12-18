#include <iostream>
using namespace std;


int main() {
    int N, sum[100001];
    int M, T, X, Y;
    unsigned long long cnt;
    string str;
    scanf("%d %d", &N, &M);
    cin >> str;

    sum[0]=0;
    for (int i=1; i<=N; ++i) {
	sum[i]+=(sum[i-1]+((str[i-1]-'0')%3))%3;
    }
    for (int i=0; i<M; ++i) {
	scanf("%d %d %d", &T, &X, &Y);
	if (T == 1) {
	    int i;
	    int dif=(((str[X-1]-'0')%3)-(Y%3)+3)%3;
	    for (i=X; i<=N; ++i) {
		sum[i]=(sum[i]-dif+3)%3;
	    }
	    str[X-1]=Y+'0';
	} else if (T == 2) {
	    int i, j;
	    cnt=0;
	    for (i=X; i<=Y; ++i) {
		for (j=i; j<=Y; ++j) {
		    if (sum[j]-sum[i-1]==0) ++cnt;
		}
	    }
	    printf("%d\n", cnt);
	}
    }
    return 0;
}
