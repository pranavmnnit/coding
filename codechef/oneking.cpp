#include<cstdio>
#include<cstring>
using namespace std;
int main() {
     int T;

     scanf("%d",&T);
     while(T--) {
     	  int start[2001]={0};
     	  int end[2001];

     	   for(int i=0;i<=2000;i++) {
          end[i]=-2; }

          int N;int count=0,due=-1;
          scanf("%d",&N);int L,R;
          for(int i=0;i<N;i++) {
               scanf("%d %d",&L,&R);
               start[L]+=1;
               if(L>end[R])
               end[R]=L;
          }
          for(int i=0;i<=2000;i++) {

               if(end[i]!=-2) {
                    if((due!=-1 && end[i]>=due) || (end[i]==i)) {
                // printf("found bomb location at %d and count %d\n",i,count+1);
                         count++;
                          due=-1;
                          continue;
                    }
		// printf("end but not due at %d  due=%d end[i] =%d \n",i,due,end[i]);
               }
                if(start[i]!=0) {
                    if(due==-1) {
                    due=i; }
                   // printf("start and due at %d\n",i);
               }

          }
	printf("%d\n",count);
     }
     return 0;
}
