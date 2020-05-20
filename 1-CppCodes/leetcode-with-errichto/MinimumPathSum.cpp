#include <bits/stdc++.h>

using namespace std;

class Solution {
    int **dp;
    int n,m;
    vector<vector<int>> grid;
public:
    int minPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        this->grid = grid;
        dp = new int*[n+1];
        for(int i=0; i<=n; i++) {
            dp[i] = new int[m+1];
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                dp[i][j] = 0;
            }
        }
        dp[0][0] = grid[0][0];
        for(int i=1; i<n; i++) {    dp[i][0] = dp[i-1][0] + grid[i][0];   }
        for(int j=1; j<m; j++) {    dp[0][j] = dp[0][j-1] + grid[0][j];   }
    
        int ret =  DP(n-1,m-1);
        return ret;
    }

    int DP(int i, int j) {
        if( (i==0) || (j == 0) ) {  return dp[i][j];    }
        else if(dp[i][j] != 0)   {  return dp[i][j];    }
        else {
            dp[i][j] = grid[i][j] + min( DP(i-1, j), DP(i, j-1) );
            return dp[i][j];
        }
        return dp[i][j];
    }
};

int main() {
    Solution s;
//     [1,3,1],
//   [1,5,1],
//   [4,2,1]
    vector<vector<int> > v = {  {1,3,1},
                                {1,5,1},
                                {4,2,1} 
                            };

    cout<<s.minPathSum(v)<<"\n";

    return 0;
}