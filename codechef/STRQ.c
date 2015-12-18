#include <stdio.h>
#include <string.h>
#define ll long long

ll upto[1000010][4];
ll pair[1000010][12];
/* c h = 0, c e = 1,  c f = 2
   h c = 3, h e = 4,  h f = 5
   e c = 6, e h = 7,  e f = 8
   f c = 9, f e = 10, f h = 12
*/

ll map[256];

int main() {
    map['c'] = 0; map['h'] = 1; map['e'] = 2; map['f'] = 3;
    ll q, ans, s, e;
    char c1, c2;
    char str[1000010]; str[0] = 'Z';
    scanf("%s", str+1);
    ll i, j;
    ll sz = strlen(str);
    for (i = sz - 1; i >= 0; --i) {
	for (j = 0; j < 4; ++j) {
	    upto[i][j] = upto[i+1][j];
	}
	for (j = 0; j < 12; ++j) {
	    pair[i][j] = pair[i+1][j];
	}
	switch (str[i]) {
	    case 'c' : upto[i][map['c']]++;
		       pair[i][0] += upto[i+1][map['h']]; // c h
		       pair[i][1] += upto[i+1][map['e']]; // c e
		       pair[i][2] += upto[i+1][map['f']]; // c f
		       break;
	    case 'h' : upto[i][map['h']]++;
		       pair[i][3] += upto[i+1][map['c']]; // h c
		       pair[i][4] += upto[i+1][map['e']]; // h e
		       pair[i][5] += upto[i+1][map['f']]; // h f
		       break;
	    case 'e' : upto[i][map['e']]++;
		       pair[i][6] += upto[i+1][map['c']]; // e c
		       pair[i][7] += upto[i+1][map['h']]; // e h
		       pair[i][8] += upto[i+1][map['f']]; // e f
		       break;
	    case 'f' : upto[i][map['f']]++;
		       pair[i][9]  += upto[i+1][map['c']]; // f c
		       pair[i][10] += upto[i+1][map['e']]; // f e
		       pair[i][11] += upto[i+1][map['h']]; // f h
		       break;
	}
    }
    scanf("%lld", &q);
    while (q--) {
	ans = 0;
	ll idx = 0;
	scanf(" %c %c %lld %lld", &c1, &c2, &s, &e);
	if (c1 == 'c') {
	    if (c2 == 'h') 	idx = 0;
	    else if (c2 == 'e') idx = 1;
	    else if (c2 == 'f') idx = 2;
	} else if (c1 == 'h') {
	    if (c2 == 'c')	idx = 3;
	    else if (c2 == 'e') idx = 4;
	    else if (c2 == 'f') idx = 5;
	} else if (c1 == 'e') {
	    if (c2 == 'c')	idx = 6;
	    else if (c2 == 'h')	idx = 7;
	    else if (c2 == 'f') idx = 8;
	} else if (c1 == 'f') {
	    if (c2 == 'c')	idx = 9;
	    else if (c2 == 'e')	idx = 10;
	    else if (c2 == 'h') idx = 11;
	}
	ll rem = (upto[s][map[c1]] - upto[e+1][map[c1]]) * 1LL * upto[e+1][map[c2]];
	printf("%lld\n", pair[s][idx] - pair[e+1][idx] - rem);
    }
    return 0;
}
