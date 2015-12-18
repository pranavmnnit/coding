#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

string findOrder(vector <string> grid) {
    int H = (int)grid.size(), W = (int)grid[0].size();
    const string Cards = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    int G[70][70] = {};
    vector<int> Id;
    for (int c = 0; c < (int)Cards.size(); ++c) {
      int mx = 100, my = 100;
      int Mx = -1, My = -1;
      for (int i = 0 ; i < H; ++i) {
	  for (int j = 0; j < W; ++j) {
	      if (grid[i][j] == Cards[c]) {
		  mx = min<int>(mx, j);
		  Mx = max<int>(Mx, j);
		  my = min<int>(my, i);
		  My = max<int>(My, i);
	      }
	 }
      }
	if (Mx != -1) {
	    Id.push_back(c);
	    for(int y=my; y<=My; y++) for(int x=mx; x<=Mx; x++) {
	    if (grid[y][x] == '.') return "ERROR!";
	    else if (grid[y][x] != Cards[c]) {
		G[c][Cards.find(grid[y][x])] = 1;
	    }
	    }
	}
    }
    int K[70] = {};
    for (vector<int>::iterator it = Id.begin(); it != Id.end(); ++it) {
      int c = *it;
      for (int i = 0; i < 70; ++i)
      if (G[c][i]) K[i]++;
    }
    string ans;
    for(;;) {
      bool up = false;
      for (vector<int>::iterator it = Id.begin(); it != Id.end(); ++it) {
        int c = *it;
        if (K[c] == 0) {
          up = true;
          ans += Cards[c];
	  for (int i = 0 ; i < 70; ++i)
          if (G[c][i]) K[i]--;
          K[c]--;
          break;
        }
      }
      if (!up) break;
    }
    bool ok = true;
      for (vector<int>::iterator it = Id.begin(); it != Id.end(); ++it) {
      int c = *it;
      if (K[c] > 0) ok = false;
    }
    if (!ok) return "ERROR!";
    return ans;
}

int main() {
    return 0;
    }
