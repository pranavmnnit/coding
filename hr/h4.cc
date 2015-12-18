#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define ull unsigned long long

ull pow2(ull a, ull b) { //2^a % b
    ull res=1, po=a, num=2;
    while(po) {
        if (po%2==0) {
            po/=2;
            num*=2;
            num%=b;
        } else {
            po--;
            res*=num;
            res%=b;
        }
    }
cout << "returning" << res << endl;
    return res;
}

ull totient(ull n)
{
    ull i, ans = n;
    
    for (i=2;i*i<=n;i++)
    {
        if (n%i==0)
            ans-=ans/i;
            
        while(n%i==0)
            n/=i;
    }    
    
    if (n!=1)
        ans-=ans/n;
cout << "tot returning=" << ans << endl;
    return ans;    
}        

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    ull a,b;
    cout << pow2(pow2(a,totient(a)), b) << endl;
    return 0;
}
