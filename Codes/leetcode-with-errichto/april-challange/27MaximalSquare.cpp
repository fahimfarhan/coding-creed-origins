#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

/**
 * @brief: dp[r][c] = best square ending at (r,c)
 * 
*/

    int maximalSquare(vector<vector<char>>& matrix) {
        int H = matrix.size();
        if(H == 0 || matrix[0].size() == 0) {   return 0;   }
        int W = matrix[0].size();

        vector<vector<int> > dp(H, vector<int>(W));
        int answer = 0;
        for(int row=0; row < H; row++) {
            for(int col=0; col <W; col++) {
                if(matrix[row][col] == '1') {
                    dp[row][col] = 1;
                    if( (row > 0) && (col > 0)) {
                        dp[row][col] += min(dp[row-1][col], dp[row][col-1], dp[row-1][col-1]);
                    }
                    answer = max(answer, dp[row][col]);
                }
            }
        }
        return answer;
    }
};

int main() {

    return 0;
}