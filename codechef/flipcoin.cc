#include <iostream>
using namespace std;
#define tr(object, it) \
    for (typeof (object.begin()) it = object.begin(); it != object.end(); ++it)

const int ma = 1e5+2;

int count[ma]; //no. of heads in the range

void query(int N, int f1, int f2) {
    ++f1; ++f2;
    int su=0;
    while (f2) {
	su += count[f2];
	f2 -= (f2 & -f2);
    }
    while (f1) {
	su -= count[f1];
	f1 -= (f1 & -f1);
    }
    return su;
}

void flip(int N, int f1, int f2) {
    ++f1; ++f2;
    count[f1]++; count[f2+1]--;
}

int main() {
    int N, Q, type;
    scanf("%d %d", &N, &Q);
    while (Q--) {
	scanf("%d %d %d", &type, &f1, &f2);
	if (type == 0) {
	    flip(N, f1, f2);
	} else if (type == 1) {
	    printf("%d\n", count(N, f1, f2));
	}
    }
    return 0;
}
