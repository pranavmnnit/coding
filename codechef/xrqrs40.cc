#include <iostream>
#include <algorithm>
using namespace std;
 
int main() {
    int M;
    int end, L, R, T, X, K;
    int arr[500010];
    end=0;
    scanf("%d", &M);
    while (M--) {
        scanf("%d", &T);
        if (T==0) {
            scanf("%d", &X);
            arr[++end]=X;
        } else if (T==1) {
            scanf("%d %d %d", &L, &R, &X);
            int num=0;
            int ma=-1;
            for (int i=L; i<=R; ++i) {
                if ((arr[i]^X) > ma) { ma=(arr[i]^X); num=arr[i]; }
            }
            printf("%d\n", num);
        } else if (T==2) {
            scanf("%d", &K);
            end-=K;
        } else if (T==3) {
            scanf("%d %d %d", &L, &R, &X);
            int cnt=0;
            for (int i=L; i<=R; ++i) {
                if (arr[i]<=X) ++cnt;
            }
            printf("%d\n", cnt);
        } else if (T==4) {
            scanf("%d %d %d", &L, &R, &K);
            int v[R-L+1];
            for (int i=L, j=0; i<=R; ++i, ++j) v[j]=arr[i];
            sort(v, v+R-L+1);
            printf("%d\n", v[K-1]);
        }
    }
    return 0;
}
