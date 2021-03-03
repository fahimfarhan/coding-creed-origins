// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

long long dp[2][101][101];

#define INVALID -1

long long maximusDp(int arr[], int isMyTurn, int p1, int p2) {
	if(p1 >= p2) {	return 0;	}
  if(dp[isMyTurn][p1][p2] != INVALID) {
    return dp[isMyTurn][p1][p2];
  }

	int turn = 0;
	if(isMyTurn == 0) {	turn = 1;	}

	int left = arr[p1] + maximusDp(arr, turn, (p1+1), p2);
	int right = arr[p2] + maximusDp(arr, turn, p1, (p2-1));

	// if(isMyTurn) {
	// 	dp[isMyTurn][p1][p2] = max(left, right);
	// }else{
	// 	dp[isMyTurn][p1][p2] = min(left, right);
	// }

	dp[isMyTurn][p1][p2] = max(left, right);
	dp[turn][p1][p2] = min(left, right);

	return dp[isMyTurn][p1][p2];
}

long long maximumAmount(int arr[], int n) {
  for(int i=0; i<2; i++) {
		for(int j=0; j<n; j++) {
			for(int k=0; k<n; k++) {
				dp[i][j][k] = INVALID;
			}
		}
	}

	for(int j=0; j<n; j++){
		dp[0][j][j] = arr[j];
		dp[1][j][j] = arr[j];
	}

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