#include<bits/stdc++.h>
#define ull unsigned long long
using namespace	std;
ull dp[9][(1LL<<22)];

int main() {
	ull t;
	cin >> t;
	while(t--){
	ull n;
	ull K,A[22]={0},total_sum=0, maxa=0;
	cin >> n >> K;
	for(ull i=0;i<n;i++){
	    cin >> A[i];
	    total_sum+=A[i];
	    if (A[i]>maxa) maxa=A[i];
	}

	if((K>n) || (total_sum%K !=0) || (maxa>(total_sum/K))) { printf("no\n");continue;}
	if (total_sum==0) { printf("yes\n"); continue; }

	memset(dp,0,9*(1LL<<22)*sizeof(dp[0][0]));

	ull X = (ull)(total_sum/K);
	dp[0][0]=1LL;
	for(ull k=0;k<K;k++){
		ull pw = 1LL<<n;
		for(ull bit=0;bit<pw;bit++){
			if(!dp[k][bit]) continue;

			ull sum=0;
			for(ull i=0;i<n;i++)
				if(bit & (1LL<<i))sum+=A[i];

			sum = sum-X*k;

			for(ull i=0;i<n;i++){
				if(bit & (1LL<<i)) continue;
				ull newmask = bit | (1LL<<i);

				if(sum+A[i]==X)
					dp[k+1LL][newmask] = 1LL;
				else if (sum+A[i]<X)
					dp[k][newmask]=1LL;
			}
		}
	}
	if(dp[K][(1LL<<n)-1LL]) printf("yes\n");
	else printf("no\n");
	}
return 0;
}
