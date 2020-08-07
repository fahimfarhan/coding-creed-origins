#include <bits/stdc++.h>

using namespace std;

/**
 * @brief: the Kadane algorithm: MS(i) = dp[i] = max(dp[i]+a[i], a[i])
 *                               local_maxima[i] = max(local_maxima[i-1]+a[i], a[i])
 *                               * i may change on 0/1 based indexing
*/
int n, *a, *dp, maximus = 0;

void MSi(){
    // base case 
    dp[0] = 0;
    for(int i=0; i<n; i++){    dp[i+1] = max(dp[i]+a[i], a[i]);    }

    maximus = INT_MIN;
    for(int i=1; i<=n; i++){   cout<<dp[i]<<" ";  maximus = max(maximus, dp[i]);      }
    cout<<"\n";

    cout<<maximus<<"\n";
}
    
int main()
{
    cin>>n;
    a = new int[n+1];
    dp = new int[n+1];
    for(int i=0; i<=n; i++){    a[i] = 0; dp[i] = 0;    }

    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    MSi();
    delete[] a;
    delete[] dp;
    return 0;
}