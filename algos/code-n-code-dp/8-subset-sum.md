We;ll use 2D array dp[N+1][M+1]

dp[i][j] = true, if you can make sum j using first i elements
         = false otherwise.


input A[] = {2, 5, 3, 4}, M = 12

Horizontal j
vertical i
  0 1 2 3 4 5 6 7 8 9 10 11 12  
0 1 0 0 0 0 0 0 0 0 0  0  0  0
1
2
3
4

dp[2][4] would be true if we can make 4 using {2, 5}. Since it is impossible, dp[2][4] = false. 

dp[0][0] = true, cz using empty set {}, we can make j=0.
dp[0][1] = false, cz we cannot make j = 1 using empty set {}.
... ...
dp[0][n] = false, cz we cannot make j = n using empty set {}.

i = 1, currentSet = {2}, we can make 0, 2 using current set. So, 


  0 1 2 3 4 5 6 7 8 9 10 11 12  
0 1 0 0 0 0 0 0 0 0 0  0  0  0
1 1 0 1 0 0 0 0 0 0 0  0  0  0
2
3
4

