#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

#define ll long long int

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


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
    ~nCr(){
        for(int i=0; i<=n;i++)
        { if(!dp[i]) delete[] dp[i]; }
        if(!dp)delete[] dp;
    }
};


// int n,m;
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

    ll m,n, minimus, maximus;
    cin>>n>>m;
    if(m==1){
        minimus = n*(n-1);
        minimus = minimus>>1;
        maximus = minimus;
        cout<<minimus<<" "<<maximus<<"\n";
        exit(0);    
    }
    // minimus
    ll d = n/m;
    ll r = n%m;

    minimus = 0;
    maximus = 0;
    ll N = n-m+1;
    if( (d+1) > N){    N=d+1; }
    nCr ncr(N,2);

    // minimus
    minimus = (m-r)*ncr.getDpIJ(d,2) + r*ncr.getDpIJ(d+1,2);
    // maximus
    maximus = ncr.getDpIJ(n-m+1,2);

    if(maximus < minimus){
        ll temp = maximus;
        maximus = minimus;
        minimus = temp;
    } 
    cout<<minimus<<" "<<maximus<<"\n";
    return 0;
}
