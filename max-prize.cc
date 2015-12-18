#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main(int argc, char** argv) {
	int t;
	cin>>t;
	while(t--){
		vector<int> v;
		int n,k,x;
		scanf("%d %d",&n,&k);
		for(int i=0;i<n;i++){
			scanf("%d",&x);
			v.push_back(x);
		}
		if(n!=0)sort(v.begin(),v.end());
                long long sum=0;
                if(k==0){
                    printf("0\n");
                    continue;
                }
                for(int i=0;i<k && (n-i-1)>=0;i++){
                    sum = sum + v[n-i-1];
                }
                 printf("%lld\n",sum);
        }
    return 0;
}
