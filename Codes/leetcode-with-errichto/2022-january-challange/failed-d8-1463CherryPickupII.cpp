#include <bits/stdc++.h>
using namespace std;

class Solution1 {
private:
  vector<vector<int>> graph;
  int **dp;

  int row, col;

  void initDp() {
      row = graph.size();
      col = graph[0].size(); 

      dp = new int*[row+1];
      for(int i=0; i<=row; i++) {
        dp[i] = new int[col+1];
      }

      for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
          dp[i][j] = -1;
        }
      }
  }

// too confusing! let's simplify this for 1 robot
int dpForSingleRobot(int ri, int rj) {
  // outOfBound
  if( (ri >= row) || (rj < 0) || (rj >= col) ) {
    return 0;
  }
  if(dp[ri][rj] != -1) {
    return dp[ri][rj];
  }

  if(rj == (row - 1)) { // last column...
    dp[ri][rj] = graph[ri][rj];
    return dp[ri][rj];
  }

  int maximus = graph[ri][rj];
  int m1 = dpForSingleRobot(ri+1, rj-1);
  int m2 = dpForSingleRobot(ri+1, rj);
  int m3 = dpForSingleRobot(ri+1, rj+1);
  int m = max(max(m1, m2), m3);
  
  maximus += m;
  dp[ri][rj] = maximus;

  return dp[ri][rj];
} 

public:
  ~Solution1() {
      for(int i=0; i<=row; i++) {
        delete[] dp[i];// = new int[col+1];
      }             
      delete[] dp; // = new int*[row+1];    
  }

    int cherryPickup(vector<vector<int>>& grid) {
      graph = grid;
      initDp();
      return dpForSingleRobot(0, 0);
    }
};


class Solution {
private:
  int ***dp;
  int row, col;

  int a[3] = {-1, 0, 1};

  void initDp(const vector<vector<int>>& grid) {
    row = grid.size();
    col = grid[0].size();

    dp = new int**[2];
    dp[0] = new int*[row+1];
    dp[1] = new int*[row+1];
    
    for(int i=0; i<=row; i++) {
      dp[0][i] = new int[col+1];
      dp[1][i] = new int[col+1];
    }

    for(int i=0; i<=row; i++) {
      for(int j=0; j<=col; j++) {
        dp[0][i][j] = -1;
        dp[1][i][j] = -1;
      }
    }
  }

/*
int dpForSingleRobot(int whichRobot, int ri, int rj, const vector<vector<int>>& graph) {
  // outOfBound
  if( (ri >= row) || (rj < 0) || (rj >= col) ) {
    return 0;
  }
  if(dp[whichRobot][ri][rj] != -1) {
    return dp[whichRobot][ri][rj];
  }

  if(rj == (row - 1)) { // last column...
    dp[whichRobot][ri][rj] = graph[ri][rj];
    return dp[whichRobot][ri][rj];
  }

  int maximus = graph[ri][rj];
  int m1 = dpForSingleRobot(whichRobot, ri+1, rj-1, graph);
  int m2 = dpForSingleRobot(whichRobot, ri+1, rj, graph);
  int m3 = dpForSingleRobot(whichRobot, ri+1, rj+1, graph);
  int m = max(max(m1, m2), m3);
  
  maximus += m;
  dp[whichRobot][ri][rj] = maximus;

  return dp[whichRobot][ri][rj];
}
*/

/** @Brief: assume r1j, r2j are different. The caller part should resolve conflict */ 
pair<int, int> dpForDoubleRobots(int ri, int r1j, int r2j, const vector<vector<int>>& grid) {
  // outOfBound
  if( (ri >= row) || (r1j < 0) || (r1j >= col) ||  (r2j < 0) || (r2j >= col)) {
    return {0, 0};
  }

  int maximusForRobot1 = -1;
  int maximusForRobot2 = -1;

  if( (dp[0][ri][r1j] != -1) && (dp[1][ri][r2j] != -1) ) {
    maximusForRobot1 = dp[0][ri][r1j];
    maximusForRobot2 = dp[1][ri][r2j];
  
    return {maximusForRobot1, maximusForRobot2};
  }

  if(ri == (row-1)) {
    maximusForRobot1 = grid[ri][r1j];
    maximusForRobot2 = grid[ri][r2j]; 
    return {maximusForRobot1, maximusForRobot2};
  }
  

  int nextRi = ri+1;
  vector<pair<int,int>> allPossibleOutcomes;
  for(int i=0; i<3; i++) {
    int nextR1j = r1j + a[i];
    for(int j=0; j<3; j++) {
      int nextR2j = r2j + a[j];
      if(nextR1j != nextR2j) {
        pair<int, int> temp = dpForDoubleRobots(nextRi, nextR1j, nextR2j, grid);
        allPossibleOutcomes.push_back(temp);
      }
    }
  } 

  int maximus = -1;
  for(auto p1: allPossibleOutcomes) {
    int sum = (grid[ri][r1j] + p1.first) + (grid[ri][r2j] + p1.second);
    if(sum > maximus) {
      maximusForRobot1 = grid[ri][r1j] + p1.first;
      maximusForRobot2 = grid[ri][r2j] + p1.second;
    }
  }

  dp[0][ri][r1j] = maximusForRobot1;
  dp[1][ri][r2j] = maximusForRobot2;
  
  return {maximusForRobot1, maximusForRobot2};
}

public:
    int cherryPickup(vector<vector<int>>& grid) {
      initDp(grid);
      auto p = dpForDoubleRobots(0, 0, col-1, grid);
      return (p.first + p.second);
    }

  ~Solution() {  
    for(int i=0; i<=row; i++) {
      delete[] dp[0][i]; // = new int[col+1];
      delete[] dp[1][i]; // = new int[col+1];
    }
    delete[] dp[0]; // = new int*[row+1];
    delete[] dp[1]; // = new int*[row+1];
    
    delete[] dp;
  }
};

int main() {

  Solution s;
  vector<vector<int>> v = {{3,1,1},{2,5,1},{1,5,5},{2,1,1}};
  int maximus = s.cherryPickup(v); 
  cout<<maximus<<"\n";
  return 0;
}