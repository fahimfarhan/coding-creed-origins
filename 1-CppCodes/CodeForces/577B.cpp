    #include<bits/stdc++.h>
     
    using namespace std;
     
    int a[1001], n, m, dp[1001][1001];
     
    int main()
    {
    	cin >> n >> m;
    	if( n > m ) return cout << "YES" << endl, 0;
    	for( int i = 0; i < n; i++ ){
    		cin >> a[i];
    	}
    	dp[0][a[0] % m] = 1;
    	for( int i = 1; i < n; i++ ){
    		dp[i][a[i] % m] = 1;
    		for( int j = 0; j < m; j++ )
    			if( dp[i - 1][j] || dp[i - 1][( j - a[i] % m + m ) % m] )
    				dp[i][j] = 1;
    	}
    	cout << ( dp[n - 1][0] ? "YES" : "NO" ) << endl;
     
    }