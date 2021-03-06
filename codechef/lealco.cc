#include <iostream>
#include <cstring>
using namespace std;

bool isCorrect(int *A, int sz, int K, int M) {
    int i,j,k,maxi, cnt;
    for (i=0;i<=(sz-K);++i) { //no. of ranges
	maxi=A[i]; cnt=0;
	for (j=i; j<(K+i); ++j) { //find max of that range
	    maxi=(A[j]>maxi?A[j]:maxi);
	}
	for (j=i; j<(K+i); ++j) { //count its count
	    if (A[j]==maxi) ++cnt;
	}
	if (cnt>=M) return false;
    }
    return true;
}

int main() {
    int T, num[18], N, M, K;
    int ans=-1;
    cin >> T;
    while (T--) {
	cin >> N >> K >> M;
	for (int i=0; i<N; ++i) {
	    cin >> num[i];
	}
	if (isCorrect(num, N, K, M)) {
	    cout << 0 << endl;
	    continue;
	}
	ans=100;
	for (int i=1; i< (1<<N); ++i) {
	    int num2[18] = {0};
	    memcpy(num2, num, 18*sizeof(int));
	    for (int j=0; j<N; ++j) {
		if (i&(1<<j)) {
		    num2[j]++;
		}
	    }
	    if (isCorrect(num2, N, K, M)) {
		int abc=__builtin_popcount(i);
		ans=(abc<ans?abc:ans);
	    }
	}
	cout << ((ans==100)?-1:ans) << endl;
    }
    return 0;
}
