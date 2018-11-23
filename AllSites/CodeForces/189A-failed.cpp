#include <bits/stdc++.h>

using namespace std;

int *dp;
int n,a,b,c;
    
int f(int m){
    
    //if(m<0){    return -9999;   }
    if(m<0){    return 0;   }
    if(m=0){    return 0;   }
    if(dp[m]!=4004){  return dp[m];   }
    else{
        // dp[m] = max(max( (1 + f(m-a) ), (1+ f(m-b)) ), (1 + f(m-c)) );
        int b1,b2,b3;
        cout<<"m-a m-b m-cc "<<m-a<<" "<<m-b<<" "<<m-c<<" \n";
        b1 = 1+f(m-a);
        b2 = 1+f(m-b);
        b3 = 1+f(m-c);
        cout<<b1<<" "<<b2<<" "<<b3<<" ";
        int maximum = max(b1,b2);
        maximum = max(maximum, b3);
        dp[m] = maximum;
        return dp[m];
    }
    return 0;
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
    cin>>n>>a>>b>>c;
    dp = new int[n+1];
    
    for(int i=0; i<=n; i++){
        dp[i] = 4004;
    }
    int count = 0;
    //  for(int i=0; i<n; i++){f(i);}
    count = f(n);
    cout<<count<<"\n";
    cout<<"\n-----------------\n";
    cout<<f(2)<<" "<<f(3)<<" "<<f(5)<<"\n";
    if(!dp)delete[] dp;


    return 0;
}