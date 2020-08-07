/* Author : Qazi Fahim Farhan (@fahimfarhan) */
/* May the CodeForces be with you! */
#include <bits/stdc++.h>

using namespace std;

#define PI 2*acos(0)

//typedef long long int ll;
 #define ll long long int
// other popular ones=> int64_t, uint64_t => use for 10^18
ll MODULO = 1e9+7;

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


// int n,m;s
vector<int> *g;
bool *isvisited;

int main(int argc, char const *argv[])
{
    /* code */
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    /*
    cout << setprecision(8);
    cout << num1 << endl;
    */
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n,k, result, x,y;
    
    ll **dp;
    ll *a;

    int T;
    cin>>T;
    for(int t=1; t<=T; t++){
        
        cin>>n>>k;
        
        result = INT_MIN;

        dp = new ll*[n+1];
        for(int i=0; i<=n; i++){    dp[i] = new ll[k+1];    }
        a = new ll[n+1];
        
        for(int i=1; i<=n; i++){    cin>>a[i];     }
        for(int i=0; i<=k; i++){    dp[0][i] = 0;   }

        for(int i=1; i<=n; i++){
            for(int j=0; j<=k; j++){
                x = max(dp[i-1][j]+a[i], a[i]);
                if( (a[i]<0) && (j>0)){
                    dp[i][j] = max(x , dp[i-1][j-1]);
                }else dp[i][j] = x;
            }
            result = max(result, dp[i][k]);
        }

        cout<<"Case "<<t<<": "<<result<<"\n";

        delete[] a;
        for(int i=0; i<=n; i++){    delete[] dp[i];     }
        delete[] dp;

    }



    return 0;
}