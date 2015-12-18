#include <iostream>
#include <cmath>
using namespace std;

int triple0(int a, int b, int c) {
    return (abs(a-1) + abs(c-1));
}
int triple1(int a, int b, int c) {
    return (abs(b-1) + abs(b-1));
}

int main() {
    int T, N, i;
    int arr[100001], best[100001][2]; // 0-> starting with non-1, 1-> starting with 1

    cin >> T;
    while (T--) {
	cin >> N;
	for (i=0; i<N; i++) {
	    cin >> arr[i];
	    best[i][0] = 0;
	    best[i][1] = 0;
	}
	if (N == 1) { cout << arr[0] << endl; continue;}
	if (N == 2) { cout << (abs(arr[0] - 1 > abs(arr[1] - 1) ? abs(arr[0] - 1) : abs(arr[1] - 1))) << endl; continue; }

	best[0][0] = triple0(arr[0], arr[1], arr[2]);
	best[0][1] = triple1(arr[0], arr[1], arr[2]);

	cout << i << N << endl;
	for (i=3; i<(N-(N%3)); i += 3) {
	    best[i][1] = max(triple1(arr[i], arr[i+1], arr[i+2]) + best[i-3][0] + abs(arr[i-1] - 1),
		             triple1(arr[i], arr[i+1], arr[i+2]) + best[i-3][1]);
	    cout << "1=" << best[i][1] << endl;

	    best[i][0] = max(triple0(arr[i], arr[i+1], arr[i+2]) + best[i-3][1] + abs(arr[i] - 1),
			     triple0(arr[i], arr[i+1], arr[i+2]) + best[i-3][0] + abs(arr[i-1] - arr[i]));
	    cout << "0=" << best[i][0] << endl;
	}
	cout << i << N << endl;
	if (N%3 == 1) {
	    best[i][1] = max(1 + best[i-3][0] + abs(arr[i-1] - 1),
		    	     1 + best[i-3][1]);

	    best[i][0] = max(arr[i] + best[i-3][0] + abs(arr[i] - arr[i-1]),
		    	     arr[i] + best[i-3][1] + abs(arr[i] - 1));
	    cout << "1=" << best[i][1] << endl;
	} else if (N%3 == 2) {
	    cout << "i+1" << abs(arr[i+1] - 1) << endl << best[i-3][0] << endl << abs(arr[i-1] - 1) << endl;
	    cout << "i+1" << abs(arr[i+1] - 1) << endl << best[i-3][1] << endl << abs(arr[i-1] - 1) << endl;
	    best[i][1] = max(abs(arr[i+1] - 1) + best[i-3][0] + abs(arr[i-1] - 1),
		             abs(arr[i+1] - 1) + best[i-3][1]);

	    best[i][0] = max(abs(arr[i] - 1) + best[i-3][1] + abs(arr[i] - 1),
		    	     abs(arr[i] - 1) + best[i-3][0] + abs(arr[i-1] - arr[i]));
	    cout << "1=" << best[i][1] << endl;
	}
	for (i=0;i<N;i++) {
	    cout << "best0 " << best[i][0];
	    cout << " best1 " << best[i][1] << endl;
	}
	cout << max(best[N-(N%3)][0], best[N-(N%3)][1]) << endl;
    }
    return 0;
}
