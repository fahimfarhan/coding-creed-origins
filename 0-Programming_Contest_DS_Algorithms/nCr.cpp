#include <bits/stdc++.h>

using namespace std;

#define ll long long int

class nCr{
private:
    ll n,r;
    ll **dp;
public:
    int getDpIJ(int i, int j){ return dp[i][j];   }
    nCr(int N, int R){
        n=N; r=R;
        dp = new ll*[n+1];
        for(int i=0; i<=n;i++){ dp[i] = new ll[r+1]; }
        dp[0][0] = 1;
        /*for(int i=0; i<=n; i++){
            dp[i][0] = 1;
        }
        for(int i=0; i<=r; i++){
            dp[0][i] = 1;
        }*/
        for(int i=1; i<=n; i++){
            for(int j=0; j<=r; j++){
                if(j>i){ dp[i][j]=0; }
                else if(j==i || j==0){ dp[i][j]=1;}
                else dp[i][j] = dp[i-1][j-1]+dp[i-1][j]; // nCr = n-1Cr-1 + n-1Cr
            }
        }
    }

    void printer(){
        for(int i=0; i<=n; i++){
            for(int j=0; j<=r; j++){
                cout<<dp[i][j]<<" ";
            }cout<<"\n";
        }
    }
    ~nCr(){
        for(int i=0; i<=n;i++)
        { if(!dp[i]) delete[] dp[i]; }
        if(!dp)delete[] dp;
    }
};

int main()
{
    int n,r;
    cout<<"Enter n, r: ";
    cin>>n>>r;
    if(r>n){
        cout<<"INVALID INPUT! r>n \n";
        exit(0);
    }
    nCr ncr(n,r);
    ncr.printer();
    return 0;
}