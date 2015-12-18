#include <iostream>
#define ull unsigned long long
#define min(a, b) (a<b?a:b)
using namespace std;

int main() {
    ull t, n, d;
    ull ans=0;
    cin >> t;
    while (t--) {
	cin >> n >> d;
	if (1==n) {
	    ans=0;
	    while (--d) {
		ans+=(d*d);
	    }
	    cout << ans << endl;
	} else if (n==2) {
		ull a[d][d];
		memset(a, 0, sizeof(a));
		for (ull i=1; i<d; ++i) {
		    a[i][0]=a[0][i]=i*i;
		}
		for (ull i=1; i<d; ++i) {
		    for (ull j=1; j<d; ++j) {
			a[i][j]=min(a[i-1][j], a[i][j-1])+((i^j)*(i+j));
		    }
		}
		cout << a[d-1][d-1] << endl;
	} else if (n==3) {
		ull  a[d][d][d];
		memset(a, 0, sizeof(a));
		for (ull i=1; i<d; ++i) {
		    a[0][0][i]=a[0][i][0]=a[i][0][0]=i*i;
		}
		for (ull i=1; i<d; ++i) {
		    for (ull j=1; j<d; ++j) {
			for (ull k=1; k<d; ++k) {
			    a[i][j][k]=min(min(a[i][j][k-1], a[i][j-1][k]), a[i-1][j][k])+((i^j^k)*(i+j+k));
			}
		    }
		}
		cout << a[d-1][d-1][d-1] << endl;
	} else if (n==4) {
	    ull  a[d][d][d][d];
	    memset(a, 0, sizeof(a));
	    for (ull i=1; i<d; ++i) {
		a[0][0][0][i]=a[0][0][i][0]=a[0][i][0][0]=a[i][0][0][0]=i*i;
	    }
	    for (ull i=1; i<d; ++i) {
		for (ull j=1; j<d; ++j) {
		    for (ull k=1; k<d; ++d) {
			for (ull l=1; l<d; ++l) {
			    a[i][j][k][l]=min(min(min(a[i][j][k][l-1], a[i][j][k-1][l]), a[i][j-1][k][l]), a[i-1][j][k][l])+
				(i^j^k^l)*(i+j+k+l);
			}
		    }
		}
	    }
	    cout << a[d-1][d-1][d-1][d-1] << endl;
	} else if (n==5) {
	    ull  a[d][d][d][d][d];
	    memset(a, 0, sizeof(a));
	    for (ull i=1; i<d; ++i) {
		a[0][0][0][0][i]=a[0][0][0][i][0]=a[0][0][i][0][0]=a[0][i][0][0][0]=a[i][0][0][0][0]=i*i;
	    }
	    for (ull i=1; i<d; ++i) {
		for (ull j=1; j<d; ++j) {
		    for (ull k=1; k<d; ++d) {
			for (ull l=1; l<d; ++l) {
			    for (ull m=1; m<d; ++m) {
				a[i][j][k][l][m]=min(min(min(min(a[i][j][k][l][m-1], a[i][j][k][l-1][m]), a[i][j][k-1][l][m]), a[i][j-1][k][l][m]),
				    a[i-1][j][k][l][m])+((i^j^k^l^m)*(i+j+k+l+m));
			    }
			}
		    }
		}
	    }
	    cout << a[d-1][d-1][d-1][d-1][d-1] << endl;
	} else if (n==6) {
	    ull  a[d][d][d][d][d][d];
	    memset(a, 0, sizeof(a));
	    for (ull i=1; i<d; ++i) {
		a[0][0][0][0][0][i]=a[0][0][0][0][i][0]=a[0][0][0][i][0][0]=a[0][0][i][0][0][0]=a[0][i][0][0][0][0]=a[i][0][0][0][0][0]=i*i;
	    }
	    for (ull i=1; i<d; ++i) {
		for (ull j=1; j<d; ++j) {
		    for (ull k=1; k<d; ++d) {
			for (ull l=1; l<d; ++l) {
			    for (ull m=1; m<d; ++m) {
				for (ull n=1; n<d; ++n) {
				    a[i][j][k][l][m][n]=min(min(min(min(min(a[i][j][k][l][m][n-1], a[i][j][k][l][m-1][n]), a[i][j][k][l-1][m][n]),
						    a[i][j][k-1][l][m][n]), a[i][j-1][k][l][m][n]), a[i-1][j][k][l][m][n])+((i^j^k^l^m^n)*(i+j+k+l+m+n));
				}
			    }
			}
		    }
		}
	    }
	    cout << a[d-1][d-1][d-1][d-1][d-1][d-1] << endl;
	} else if (n==7) {
	    ull  a[d][d][d][d][d][d][d];
	    memset(a, 0, sizeof(a));
	    for (ull i=1; i<d; ++i) {
		a[0][0][0][0][0][i][0]=a[0][0][0][0][i][0][0]=a[0][0][0][i][0][0][0]=a[0][0][i][0][0][0][0]=a[0][i][0][0][0][0][0]=a[i][0][0][0][0][0][0]
		    =a[0][0][0][0][0][0][i]=i*i;
	    }
	    for (ull i=1; i<d; ++i) {
		for (ull j=1; j<d; ++j) {
		    for (ull k=1; k<d; ++d) {
			for (ull l=1; l<d; ++l) {
			    for (ull m=1; m<d; ++m) {
				for (ull n=1; n<d; ++n) {
				    for (ull o=1; o<d; ++d) {
					a[i][j][k][l][m][n][o]=min(min(min(min(min(min(a[i][j][k][l][m][n][o-1], a[i][j][k][l][m][n-1][o]),
							    a[i][j][k][l][m-1][n][o]), a[i][j][k-1][l][m][n][o]), a[i][j-1][k][l][m][n][o]),
						a[i-1][j][k][l][m][n][o]), a[i][j][k][l-1][m][n][o])+((i^j^k^l^m^n^o)*(i+j+k+l+m+n+o));
				    }
				}
			    }
			}
		    }
		}
	    }
	    cout << a[d-1][d-1][d-1][d-1][d-1][d-1][d-1] << endl;
	} else if (n==8) {
	    ull  a[d][d][d][d][d][d][d][d];
	    memset(a, 0, sizeof(a));
	    for (ull i=1; i<d; ++i) {
		a[0][0][0][0][0][i][0][0]=a[0][0][0][0][i][0][0][0]=a[0][0][0][i][0][0][0][0]=a[0][0][i][0][0][0][0][0]=a[0][i][0][0][0][0][0][0]=
		    a[i][0][0][0][0][0][0][0]=a[0][0][0][0][0][0][i][0]=a[0][0][0][0][0][0][0][i]=i*i;
	    }
	    for (ull i=1; i<d; ++i) {
		for (ull j=1; j<d; ++j) {
		    for (ull k=1; k<d; ++d) {
			for (ull l=1; l<d; ++l) {
			    for (ull m=1; m<d; ++m) {
				for (ull n=1; n<d; ++n) {
				    for (ull o=1; o<d; ++d) {
					for (ull p=1; p<d; ++p) {
					    a[i][j][k][l][m][n][o][p]=min(min(min(min(min(min(min(a[i][j][k][l][m][n][o][p-1], a[i][j][k][l][m][n][o-1][p]),
								a[i][j][k][l][m][n-1][o][p]), a[i][j][k][l][m-1][n][o][p]), a[i][j][k][l-1][m][n][o][p]),
						    a[i][j][k-1][l][m][n][o][p]), a[i][j-1][k][l][m][n][o][p]),a[i-1][j][k][l][m][n][o][p] )+
						((i^j^k^l^m^n^o^p)*(i+j+k+l+m+n+o+p));
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	    cout << a[d-1][d-1][d-1][d-1][d-1][d-1][d-1][d-1] << endl;
	} else if (n==9) {
	    ull  a[d][d][d][d][d][d][d][d][d];
	    memset(a, 0, sizeof(a));
	    for (ull i=1; i<d; ++i) {
		a[0][0][0][0][0][0][0][0][i]=a[0][0][0][0][0][0][0][i][0]=a[0][0][0][0][0][0][i][0][0]=a[0][0][0][0][0][i][0][0][0]=
		    a[0][i][0][0][0][0][0][0]=a[i][0][0][0][0][0][0]=a[0][0][0][0][0][0][i][0]=a[0][0][0][0][0][0][0][i]=i*i;
	    }
	    for (ull i=1; i<d; ++i) {
		for (ull j=1; j<d; ++j) {
		    for (ull k=1; k<d; ++d) {
			for (ull l=1; l<d; ++l) {
			    for (ull m=1; m<d; ++m) {
				for (ull n=1; n<d; ++n) {
				    for (ull o=1; o<d; ++d) {
					for (ull p=1; p<d; ++p) {
					    for (ull q=1; q<d; ++q) {
						a[i][j][k][l][m][n][o][p][q]=min(min(min(min(min(min(min(min(a[i][j][k][l][m][n][o][p][q], 
										a[i][j][k][l][m][n][o][p-1][q]),
								    a[i][j][k][l][m][n][o-1][p][q]), 
									a[i][j][k][l][m][n-1][o][p][q]), 
								    a[i][j][k][l][m-1][n][o][p][q]),
							a[i][j][k][l-1][m][n][o][p][q]), 
							    a[i][j][k-1][l][m][n][o][p][q]),a[i][j-1][k][l][m][n][o][p][q] ),
						    a[i-1][j][k][l][m][n][o][p][q])+
						    ((i^j^k^l^m^n^o^p^q)*(i+j+k+l+m+n+o+p+q));
					    }
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	    cout << a[d-1][d-1][d-1][d-1][d-1][d-1][d-1][d-1][d-1] << endl;
	}
	    else if (n==10) ull a[d][d][d][d][d][d][d][d][d][d];
    }
    return 0;
}
