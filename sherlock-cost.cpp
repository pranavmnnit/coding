#include <iostream>
#include <cmath>
using namespace std;

int maxim3(int a, int b, int c, bool* c1) {
    if ((abs(b-1) + abs(1-b)) > abs(a-1) + abs(c-1)) {
        *c1 = true;
        //cout << "setting c1 true for" << a << b << c << endl;
        return (abs(b-1) + abs(1-b));
    } else {
        *c1 = false;
        //cout << "setting c1 false for" << a << b << c << endl;
        return (abs(a-1) + abs(1-c));
    }
}

int main() {
    int T,N,arr[100001];
    long maxupto[100001] = {0};
    long maxnumupto[100001] = {0}, answer[100001] = {0};
    bool c1 = true;
    cin >> T;
    for (int k=0;k<T;k++) {
        cin >> N;
        for (int i=0; i<N; i++) {
            cin >> arr[i];
        }
        for (int i=0; i<N; i++) {
            maxupto[i] = 0;
            maxnumupto[i] = 0;
        }
        
        if (N == 1) { answer[k] = arr[N-1]; continue; }
        if (N == 2) { answer[k] = (abs(1-arr[N-1]) > abs(arr[N-2]-1) ? abs(1-arr[N-1]) : abs(arr[N-2]-1)); continue; }
        

        maxupto[0] = 0;
        maxnumupto[0] = arr[0];
        maxupto[1] = (abs(1-arr[1]) > abs(arr[0]-1) ? abs(1-arr[1]) : abs(arr[0]-1));
        maxnumupto[1] = (abs(1-arr[1]) > abs(arr[0]-1) ? arr[1] : 1);
       
        for (int i=1; i<N-1; i++) {
            if (i==1) {
                maxupto[i+1] = maxim3(arr[i-1], arr[i], arr[i+1], &c1);
                maxnumupto[i+1] = ((c1 == true) ? 1 : arr[i+1]);
            } else {
                if (maxupto[i-2] + abs(arr[i-1] - maxnumupto[i-2]) + abs(1 - arr[i-1]) + abs(arr[i+1] - 1) >
                    maxupto[i-2] + abs(maxnumupto[i-2] - 1) + abs(arr[i] - 1) + abs(arr[i] - 1)) {
                    
                    maxupto[i+1] = maxupto[i-2] + abs(arr[i-1] - maxnumupto[i-2]) + abs(1 - arr[i-1]) + abs(arr[i+1] - 1);
                    maxnumupto[i+1] = arr[i+1];
                } else {
                    maxupto[i+1] = maxupto[i-2] + abs(maxnumupto[i-2] - 1) + abs(arr[i] - 1) + abs(arr[i] - 1);
                    maxnumupto[i+1] = 1;
                }
            }
        }
       
        answer[k] = maxupto[N-1];
    }
    for (int t=0; t<T;t++) {
        cout << answer[t] << endl;
    }
    return 0;
}
