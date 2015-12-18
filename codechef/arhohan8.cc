#include <iostream>
using namespace std;

int arr[16][16];

void pre() {
    for (int i=1; i<=15; ++i) {
	arr[i][1]=arr[1][i]=1;
    }
    for (int i=2; i<=15; ++i) {
	for (int j=2; j<=15; ++j) {
	    arr[i][j]=arr[i-1][j]+arr[i][j-1];
	}
    }
}

int main() {
    int N;
    cin >> N;
    pre();
    int sum=0;
    for (int i=1; i<=N; ++i) {
	sum+=arr[N][i];
    }
    cout << sum << endl;
    return 0;
}
