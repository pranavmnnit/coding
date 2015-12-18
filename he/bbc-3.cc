#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int T;
    long long N,m;
    cin>>T;
    while(T--){
	m=0;
	cin>>N;
	//if(N==1){cout<<8<<endl;continue;}
	long long sqt = (long long )sqrt(N);
	for (long long i=1;i<=sqt; i++){
	    if(N%i==0) {
		long long div=0;
		div=N/i;
		if(i%4!=0)m=m+i;
		if((i != div) && (div%4!=0))m=m+div;
	    }
	}
	cout<<8*m<<endl;
    }
return 0;
}
