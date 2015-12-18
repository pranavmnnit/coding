#include<iostream>
using namespace std;

int main() {
    long long sum=0;
    string str;
    cin >> str;
    long long sz=str.size();
    for (long long d=1; d<=sz; ++d) {
	for (long long i=0; i<sz-d+1; ++i) {
	    long long cur=0;
	    for (long long j=i; j-i<d; ++j) {
		cur=(cur*10)+(str[j]-'0');
	    }
	    sum+=cur;
	}
    }
    cout << sum << endl;
    return 0;
}
