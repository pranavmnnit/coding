#include<bits/stdc++.h>
using namespace	std;

typedef long long int LL;

LL A[20],idx=1;

void get_numbers(LL a){
	while(a){
		A[idx++]=a%10;
		a=a/10;
	}
}

long arr[4]; //2, 3, 5, 7

int main(){
	LL n,a;
	cin >> n >> a;
	get_numbers(a);

	for (int i = 1; i <= idx; ++i) {
	    switch(A[i]) {
		case 2: arr[0]++; break;
		case 3: arr[0]++; arr[1]++; break;
		case 4: arr[0]+=3; arr[1]++; break;
		case 5: arr[0]+=3; arr[1]++; arr[2]++; break;
		case 6: arr[0]+=4; arr[1]+=2; arr[2]++; break;
		case 7: arr[0]+=4; arr[1]+=2; arr[2]++; arr[3]++; break;
		case 8: arr[0]+=7; arr[1]+=2; arr[2]++; arr[3]++; break;
		case 9: arr[0]+=7; arr[1]+=4; arr[2]++; arr[3]++; break;
		default: break;
	    }
	}
	if (arr[3] > 0) {
	    for (int i = 0; i < arr[3]; ++i) {
		cout << "7";
	    }
	    arr[0] -= (arr[3]*4);
	    arr[1] -= (arr[3]*2);
	    arr[2] -= arr[3];
	}
	if (arr[2] > 0) {
	    for (int i = 0; i< arr[2]; ++i) {
		cout << "5";
	    }
	    arr[0] -= (arr[2]*3);
	    arr[1] -= arr[2];
	}
	if (arr[1] > 0) {
	    for (int i = 0; i < arr[1]; ++i) {
		cout << "3";
	    }
	    arr[0] -= arr[1];
	}
	if (arr[0] > 0) {
	    for (int i = 0; i < arr[0]; ++i) {
		cout << "2";
	    }
	}
	cout << endl;
	return 0;
}
