#include <iostream>
using namespace std;

long long tree[1000010];
long long A[1000010];
long long B[1000010];

void update(long long idx, long long val, long long n) {
    while (idx<=n) {
	tree[idx]+=val;
	idx+=(idx&-idx);
    }
}

long long upto(long long idx, long long n) {
    long long sum=0;
    while (idx>0) {
	sum+=tree[idx];
	idx-=(idx&-idx);
    }
    return sum;
}

bool isprime(long long num) {
    for (long long i=2; i*i<=num; i++) {
	if (num%i==0) return false;
    }
    return true;
}

int main() {
    long long n, ma=-1;
    long long cnt=0;
    cin >> n;
    for (long long i=1; i<=n; ++i) {
	cin >> A[i];
	if (A[i]>ma) ma=A[i];
    }
    for (long long i=1; i<=n; ++i) {
	cin >> B[i];
	if (B[i]>ma) ma=B[i];
    }
    for (long long i=n; i>0; --i) {
	cnt+=upto(A[i], ma);
	update(B[i], 1, ma);
    }
    cout << (isprime(cnt)?"MAGIC INVERSION":"SIMPLE INVERSION") << endl;
}
