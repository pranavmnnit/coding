#include <iostream>
using namespace std;
const int MAXN = 1000;

int border[MAXN];
void calculate_border(string s) {
  int i = 1, j = -1, n = s.size();
  border[0] = -1;
  while(i < n) {
    while(j >= 0 && s[i] != s[j+1]) j = border[j];
    if (s[i] == s[j+1]) j++;
    border[i++] = j;
  }
}

int main() {
    string str;
    cin >> str;
    calculate_border(str);
    for (int i=0; i<=str.size(); ++i) {
	cout << border[i] << endl;
    }
    return 0;
}
