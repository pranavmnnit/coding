#include <stdio.h>

int main() {
    int n, i;
    int A, B;
    int ma[100010]={0};
    int a[100010];
    scanf("%d", &n);
    for (i=1; i<=n; ++i) {
	scanf("%d", &a[i]);
    }
    for (i=1; i<=n; ++i) {
	printf("%d\t", ma[i]);
    }
    printf("\n");
    scanf("%d", &n);
    for (i=0; i<n; ++i) {
	scanf("%d %d", &A, &B);
	if (ma[A]>B) printf("YES\n");
	else printf("NO\n");
    }
    return 0;
}
