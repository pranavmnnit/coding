#include <stdio.h>
#include <string.h>

int upto[1000010][4];
int map[256];

int main() {
    map['c'] = 0; map['h'] = 1; map['e'] = 2; map['f'] = 3;
    int q, ans, s, e;
    char c1, c2;
    char str[1000010]; str[0] = 'Z';
    scanf("%s", str+1);
    int i, j;
    int sz = strlen(str);
    for (i = 1; i < sz; ++i) {
	for (j = 0; j < 4; ++j) {
	    upto[i][j] = upto[i-1][j];
	}
	if (str[i] == 'c')      upto[i][0]++;
	else if (str[i] == 'h') upto[i][1]++;
	else if (str[i] == 'e') upto[i][2]++;
	else if (str[i] == 'f') upto[i][3]++;
    }
    scanf("%d", &q);
    while (q--) {
	ans = 0;
	scanf(" %c %c %d %d", &c1, &c2, &s, &e);
	for (i = s; i <= e; ++i) {
	    if (str[i] == c1) {
		ans += (upto[e][map[c2]] - upto[i][map[c2]]);
	    }
	}
	printf("%d\n", ans);
    }
    return 0;
}
