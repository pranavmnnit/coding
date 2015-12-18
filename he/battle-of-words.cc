#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int t, i;
    char ch;
    char str1[100010], str2[100010];
    scanf("%d ", &t);
    while (t--) {
	fgets(str1, 100010, stdin);
	fgets(str2, 100010, stdin);
	//printf("str1= %s\n", str1);
	//printf("str2= %s\n", str2);
	int cnt1[26] = {0}, cnt2[26] = {0};
	for (i = 0; str1[i]; ++i) (str1[i] != ' ' && ++cnt1[str1[i] - 'a']);
	for (i = 0; str2[i]; ++i) (str2[i] != ' ' && ++cnt2[str2[i] - 'a']);

	for (i = 0; i < 26; ++i) {
	    printf("%d\t%d\n", cnt1[i], cnt2[i]);
	}

	for (i = 0; i < 26; ++i) {
	    if ((!cnt1[i] && !cnt2[i]) || (cnt1[i] > cnt2[i])) continue;
	    else break;
	}
	if (i == 26) {
	    printf("You win some.\n");
	    continue;
	}

	for (i = 0; i < 26; ++i) {
	    if ((!cnt1[i] && !cnt2[i]) || (cnt2[i] > cnt1[i])) continue;
	}
	if (i == 26) {
	    printf("You lose some.\n");
	    continue;
	}

	printf("You draw some.\n");
    }
    return 0;
}
