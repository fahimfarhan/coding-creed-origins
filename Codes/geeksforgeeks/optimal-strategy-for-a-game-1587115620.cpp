// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

// recursive soln
long long maximus(int arr[], int isMyTurn, int p1, int p2) {
  if(p1 > p2) { return 0; }
  int turn = 0;
  if(isMyTurn == 0) { turn = 1; }
  // if I take left
  long long left = maximus(arr, turn, (p1+1), p2);

  // if I take right 
  long long right = maximus(arr, turn, p1, (p2-1));

  if(isMyTurn) {
    left += arr[p1];
    right += arr[p2];
  }

  if(isMyTurn) {
    return max(left, right);
  }else{
    return min(left, right);
  }

}

long long dp[2][101][101];

void initDp() {
  for(int i=0; i<101; i++) {
    for(int j=0; j<101; j++) {
      dp[0][i][j] = -1;
      dp[1][i][j] = -1;
    }
  }
}


long long maximusDp(int arr[], int isMyTurn, int p1, int p2) {
  if(p1 > p2) { return 0; }
  if(dp[isMyTurn][p1][p2] != -1) {  return dp[isMyTurn][p1][p2];  }

  int turn = 0;
  if(isMyTurn == 0) { turn = 1; }
  // if I take left
  long long left = maximusDp(arr, turn, (p1+1), p2);

  // if I take right 
  long long right = maximusDp(arr, turn, p1, (p2-1));

  if(isMyTurn) {
    left += arr[p1];
    right += arr[p2];
  }

  if(isMyTurn) {
    dp[isMyTurn][p1][p2] = max(left, right);
  }else{
    dp[isMyTurn][p1][p2] = min(left, right);
  }
  return dp[isMyTurn][p1][p2];
}

long long maximumAmount(int arr[], int n) 
{
    // Your code here
    initDp();
    return maximusDp(arr, 1, 0, (n-1));
}

// { Driver Code Starts.

int main() {
    
    //taking total testcases
	int T;
	cin>>T;
	while(T--)
	{
	    //taking number of elements
	    int N;
	    cin>>N;
	    
	    int A[N];
	    
	    //inserting the elements
	    for(int i=0;i<N;i++)
	    cin>>A[i];
	    
	    //calling function maximumAmount()
	    cout<<maximumAmount(A,N)<<endl;
	    
	}
	return 0;
}  // } Driver Code Ends