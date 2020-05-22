#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int **dp;
    string s, t;
    int DP(int i, int j) {
        if( (i<0) || (j<0) ) {  return 0;     } 
        if(dp[i][j] != -1) {    return dp[i][j];    }
        else{
            // calc dp i j
            if(s[i] == t[j]) {
                dp[i][j] = 1 + DP((i-1), (j-1));
            }else{
                dp[i][j] = max( DP(i,j-1), DP(i-1,j));
            }
            return dp[i][j];
        }
        return 0;
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(); int m = text2.size();
        
        this->s = text1;
        this->t = text2;

        dp = new int*[n+1];
        for(int i=0; i<=n; i++) {   
            dp[i] = new int[m+1];   
            for(int j=0; j<=m; j++) {   dp[i][j] = -1;  }    
        }

        int maximus = DP( (n-1),(m-1) );

        for(int i=0; i<=n; i++) {   delete[] dp[i]; }
        delete[] dp;

        return maximus;
    }
};

int main() {

    return 0;
}