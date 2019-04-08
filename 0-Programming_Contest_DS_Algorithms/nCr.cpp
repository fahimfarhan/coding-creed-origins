#include <bits/stdc++.h>

using namespace std;

class nCr{
private:
    int n,r;
    int **dp;
public:
    int getDpIJ(int i, int j){ return dp[i][j];   }
    nCr(int N, int R){
        n=N; r=R;
        dp = new int*[n+1];
        for(int i=0; i<=n;i++){ dp[i] = new int[r+1]; }
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
    nCr ncr(n,r);
    return 0;
}