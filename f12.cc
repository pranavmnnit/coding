#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int getmin(string s) {
int inf,n,i,j,f[55];
long long k,cur; 
n=s.length();
memset(f,120,sizeof(f));
inf=f[0]; f[0]=0;
for (i=0; i<n; i++) if (f[i]<inf && s[i]=='1') {
    for (j=i, k=0; j<n; j++) {
	k=k*2+s[j]-'0';
	cur=k;
	while (cur%5==0) cur/=5;
	if (cur==1) f[j+1]=min(f[j+1],f[i]+1);
    }
}
return f[n]<inf?f[n]:-1;
}

int main() {
    string str;
    while (1) {
	    cin >> str;
	    cout << getmin(str) << endl;
    }
    return 0;
}
