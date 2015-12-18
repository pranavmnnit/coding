#include <stdio.h>

long long arr[22];
int main()
{
    int t,n,k,i,j;
    long long sum=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&k);
        sum=0;
        for(i=0;i<n;++i){ scanf("%lld",&arr[i]); sum+=arr[i]; }
        //printf("%lld\n",sum);
        if(n<k || sum%k!=0)
        {
            printf("no\n");
            continue;
        }
        if(sum==0)
        {
            printf("yes\n");
            continue;
        }
        sum=sum/k;
        int used=0,cnt=0,c;
        long long curr=0;
        for(i=(1<<n)-1;i>=1;--i)
        {
            if((i&used)!=0) continue;
            j=0;
            c=i; curr=0;
            while(c>0)
            {
                if(c&1) curr+=arr[j];
                if(curr>sum) break;
                j++;
                c>>=1;
            }
            if(curr==sum){ used|=i; cnt++;}
        }
        if(cnt>=k) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
