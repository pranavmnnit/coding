#include <iostream>
#include <cstring>
#define N0(a) (((a)*(a+1))/2)
#define N1(a) (((a)*(a-1))/2)
#define N2(a) (((a)*(a-1))/2)
#define NUM(ch) (((ch-'0')%3))
#define ull unsigned long long
using namespace std;

ull cnt[300030][3];
ull sum[300030];
char str[100010];

void createSegTree(ull idx, char* str, ull beg, ull end, ull N) {
    if (beg==end) {
	cnt[idx][NUM(str[beg-1])]++;
	sum[idx]=NUM(str[beg-1]);
	return;
    }
    createSegTree(idx*2, str, beg, (beg+end)/2, N);
    createSegTree(idx*2+1, str, (end+beg)/2+1, end, N);
    sum[idx]=(sum[idx*2]+sum[idx*2+1])%3;
    cnt[idx][0]=cnt[idx*2][0]; cnt[idx][1]=cnt[idx*2][1]; cnt[idx][2]=cnt[idx*2][2];

    cnt[idx][sum[idx*2]] += cnt[idx*2+1][0];
    cnt[idx][(sum[idx*2]+1)%3] += cnt[idx*2+1][1];
    cnt[idx][(sum[idx*2]+2)%3] += cnt[idx*2+1][2];
}

void retRange(ull idx, ull beg, ull end, ull L, ull R, ull *ans, ull *from) {
    ull l[3]={0}, r[3]={0}; ull lfrom=0, rfrom=0;
    if (L>end || R<beg) return;
    if (beg>=L && end<=R) {
	ans[0]=cnt[idx][0]; ans[1]=cnt[idx][1]; ans[2]=cnt[idx][2];
	*from=sum[idx];
       	return;
    }
    retRange(idx*2, beg, (beg+end)/2, L, R, l, &lfrom);
    retRange(idx*2+1, (beg+end)/2+1, end, L, R, r, &rfrom);
    *from=(lfrom+rfrom)%3;
    if ((!l[0] && !l[1] && !l[2]) || (!r[0] && !r[1] && !r[2])) {
	ans[0] = l[0]+r[0]; ans[1] = l[1]+r[1]; ans[2] = l[2]+r[2];
    } else {
	ans[0]=l[0]; ans[1]=l[1]; ans[2]=l[2];
	if (lfrom==0)		{ ans[0]+=r[0]; ans[1]+=r[1]; ans[2]+=r[2]; }
	else if (lfrom==1)	{ ans[0]+=r[2]; ans[1]+=r[0]; ans[2]+=r[1]; }
	else 			{ ans[0]+=r[1]; ans[1]+=r[2]; ans[2]+=r[0]; }
    }
}

void updateRange(ull idx, ull beg, ull end, ull at, ull val) {
    if (beg==end) {
	cnt[idx][0]=cnt[idx][1]=cnt[idx][2]=0;
	cnt[idx][val%3]++;
	sum[idx]=val%3;
	return;
    }
    ull mid = (end+beg)/2;
    if (at<=mid) {
	updateRange(idx*2, beg, (beg+end)/2, at, val);
    } else {
	updateRange(idx*2+1, (beg+end)/2+1, end, at, val);
    }
    sum[idx]=(sum[idx*2]+sum[idx*2+1])%3;

    cnt[idx][0]=cnt[idx*2][0]; cnt[idx][1]=cnt[idx*2][1]; cnt[idx][2]=cnt[idx*2][2];
    cnt[idx][(sum[idx*2]+0)%3] += cnt[idx*2+1][0];
    cnt[idx][(sum[idx*2]+1)%3] += cnt[idx*2+1][1];
    cnt[idx][(sum[idx*2]+2)%3] += cnt[idx*2+1][2];
}

void printTree() {
    cout << "\n---------------------------------------\n";
    for (ull i=1; i<=30; ++i) {
	cout << i << "  " << cnt[i][0] << "\t" << cnt[i][1] << "\t" << cnt[i][2] << endl;
    }
    cout << "\n---------------------------------------\n";
}

int main() {
    ull N;
    ull M, T, X, Y;
    scanf("%llu %llu", &N, &M);
    scanf("%s", str);
    createSegTree(1, str, 1, N, N);

    for (ull i=0; i<M; ++i) {
	scanf("%llu %llu %llu", &T, &X, &Y);
	if (T == 1) {
	    str[X-1]=Y+'0';
	    updateRange(1, 1, N, X, Y);
	} else if (T == 2) {
	    ull ans[3]={0}, n=0;
	    retRange(1, 1, N, X, Y, ans, &n);
	    printf("%llu\n", N0(ans[0])+N1(ans[1])+N2(ans[2]));
	}
    }
    return 0;
}
