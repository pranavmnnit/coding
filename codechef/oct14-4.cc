#include <iostream>
using namespace std;

inline long Maxim(long a, long b, long c) {
    return (a>b?(a>c?a:c):(b>c?b:c));
}

int main() {
    int T;
    int R, G, B, M, Mr, Mg, Mb;
    long arr[110];
    cin >> T;
    while (T--) {
	Mr = Mg = Mb = 0;
	cin >> R >> G >> B >> M;
	for (int i=0; i<R; ++i) {
	    cin >> arr[i];
	    if (Mr < arr[i]) Mr = arr[i];
	}
	for (int i=0; i<G; ++i) {
	    cin >> arr[i];
	    if (Mg < arr[i]) Mg = arr[i];
	}
	for (int i=0; i<B; ++i) {
	    cin >> arr[i];
	    if (Mb < arr[i]) Mb = arr[i];
	}
	while (M--) {
	    if (Mr && Mr>=Mg && Mr>=Mb) {
		Mr >>= 1;
	    } else if (Mg && Mg>=Mr && Mg>=Mb) {
		Mg >>= 1;
	    } else {
		Mb >>= 1;
	    }
	}
	cout << Maxim(Mr, Mg, Mb) << endl;
    }
    return 0;
}
