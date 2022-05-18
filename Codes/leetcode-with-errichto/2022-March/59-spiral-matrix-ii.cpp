#include <bits/stdc++.h>
using namespace std;

#define RIGHT 0
#define DOWN 1
#define LEFT 2
#define UP 3

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<int> row(n, -1);
        vector<vector<int>> g(n, row);

        int d = RIGHT;
        int num = 1;
        int nSquare = n * n;

        int i = 0, j = 0;

        while(num <= nSquare) {
          g[i][j] = num;
          num++;

          for(int k = 0; k <4; k++) {
            int d1 = d + k;
            if(d1 > 3) {
              d1 -= 4;
            }
            if(canGo(d1, i, j, n, g)) {
              d = d1;
              if(d == RIGHT) {
                j = j + 1;
              } else if(d == DOWN) {
                i = i + 1;
              } else if(d == LEFT) {
                j = j - 1;
              } else if(d == UP) {
                i = i - 1;
              }  
              break;
            }
          }
        }
        return g;
    }

    
    bool canGo(const int& d, const int& i1, const int& j1, const int& n, const vector<vector<int>> g) {
          int i = i1, j = j1;
          
          if(d == RIGHT) {
            j = j1 + 1;
          } else if(d == DOWN) {
            i = i1 + 1;
          } else if(d == LEFT) {
            j = j1 - 1;
          } else if(d == UP) {
            i = i1 - 1;
          }

          if(i < 0) return false;
          if(i >= n) return false;
          if(j < 0) return false;
          if(j >= n) return false;

          if(g[i][j] == -1) {
            return true;
          }
          return false;
        }
};

int main() {

  Solution s;
  int n = 3;
  auto g = s.generateMatrix(n);

  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      cout<<g[i][j]<<" ";
    }cout<<"\n";
  }

  return 0;
}