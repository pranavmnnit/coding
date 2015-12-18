#include <iostream>
#include <cstring>
#include <set>
#define tr(obj, it)	\
    for(typeof(obj.begin()) it=obj.begin(); it!=obj.end(); ++it)
using namespace std;

int main() {
    int N, a, b, T, cnt,cur_a,cur_b;
    bool done[2001];
    scanf("%d", &T);
    while (T--) {
        memset(done, 0, 2001);
        cnt=0;
        scanf("%d", &N);
        for (int i=0; i<N; ++i) {
	    bool flag=false;
            scanf("%d %d", &a, &b);
	    for (int j=a; j<=b; ++j)
		if (done[j]) flag=1;
	    if (flag) continue;
            cnt++;
            for (int i=a; i<=b; ++i) done[i]=true;
        }
        printf("%d\n", cnt);
    }
    return 0;
}
