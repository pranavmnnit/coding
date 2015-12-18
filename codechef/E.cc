#include <iostream>
using namespace std;
const long long mod =1e9+7;

int fail[1000010];
void failure(string& str, int* fail) {
        long sz = str.size();
	    fail[0] = fail[1] = 0;
	        for (long i=2; i <= sz; i++) {
		            long j = fail[i-1];
			            while(1) {
					            if (str[i-1] == str[j]) {
							                fail[i] = j+1;
									                break;
											            }
						                if (j == 0) {
								                    fail[i] = 0;
										                    break;
												                }
								            j = fail[j];
									            }
				        }
}
long long pow2(long long N) {
        long long in = 0;
	    if (N == 0) return 1;
	        in = pow2(N/2);
		    in *= in;
		        in %= mod;
			    if (N%2 != 0) {
				        in *= 2;
					        in %= mod;
						    }
			        return in;
}

long long E(string& str) {
    bool done[1000010] = {false};
    long long sum = 0;
    done[0] = true;
    int k,j;
    memset(fail, 0, sizeof(int)*1000010);
    failure(str, fail);
    int sz = str.size();
    for (int i=0; i<=sz; ++i) {
        if (!done[fail[i]]) {
            done[fail[i]] = true;
	    cout << "check for.. " << fail[i] << endl;
	    k = 0; j = sz-fail[i];
	    while ((j<sz) && (str[k] == str[j])) {
		++j; ++k;
		if (j == sz) {
		    cout << "found.." << endl;
		    sum += pow2(fail[i]);
		    sum %= mod;
		    break;
		}
	    }
        }
    }
    sum += pow2(sz);
    sum %= mod;
    return sum;
}

int main() {
    string str;
    cin >> str;
    cout << E(str);
    return 0;
}
