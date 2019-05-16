#include <bits/stdc++.h>

using namespace std;

const int N = 300000+13;
int dp[N][3][3];
// dp[pos][state max][state mul]
int n,x,*a;


int main(){

    cin>>n>>x;
    a = new int[n+1];
    for(int i=0; i<n; i++){ cin>>a[i];  }

    for(int i=0; i<N; i++){
        for(int j=0; j<3; j++){
            for(int k = 0;k<3;k++){
                dp[i][j][k]=INT_MAX;
            }
        }
    }

    dp[0][0][0]=0;
    for(int i=0; i<=n; i++){
        for(int j=0; j<=2; j++){
            for(int k=0; k<=2; k++){
                if(k<2){ dp[i][j][k+1] = max(dp[i][j][k+1], dp[i][j][k]);    }
                if(j<2){ dp[i][j+1][k] = max(dp[i][j+1][k], dp[i][j][k]);    }
                if(i<2){ 
                    //    dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k]);    
                    // dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k] + (j == 1 ? a[i] : 0) * li(k == 1 ? x : 1));
                    int temp = 0;
                    if(j==1){ temp = a[i]; }else{   temp = 0; }
                    if(k==1){   temp=temp*x; }
                    dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k]+temp);                   
                }
            }
        }
    }
    cout<<dp[n][2][2]<<"\n";
    delete[] a;
    return 0;
}