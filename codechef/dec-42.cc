#include <iostream>
#include <vector>
#define ll long long
#define ull unsigned long long
#define tr(ob, it) \
    for(typeof(ob.begin()) it=ob.begin(); it!=ob.end(); ++it)
using namespace std;

ll A[1001];

int f(int a, int b) { //returns status of A[a..b]
    if (a==b) return 0;
}

int main() {
    int N;
    ll a;
    cin >> N;
    for (int i=0; i<N; ++i) {
	cin >> A[i];
    }
    cout << 1+f(0, N-1) << endl;
    return 0;
}
