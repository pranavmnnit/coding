#include <iostream>

inline void scanint(int &x)
{
 register int c = getchar_unlocked();
 x = 0;
 for(;(c<48 || c>57);c = getchar_unlocked())
  ;
 for(;c>47 && c<58;c = getchar_unlocked())
 {
   x = (x<<1) + (x<<3) + c - 48;
 }
}

using namespace std;

int main() {
    int T, N, K;
    int a;
    scanint(T);
    while (T--) {
	bool ans[1024]={0};
        scanint(N); scanint(K); ans[0]=1;
        int ma=K;
        for (int i=0; i<N; ++i) {
            scanint(a);
	    for (int j=0; j<1024; ++j) {
		if (ans[j]) {ans[a^j]=1;
		ma=(a^j^K)>ma?(a^j^K):ma;}
	    }
        }
        printf("%d\n", ma);
    }
    return 0;
}
