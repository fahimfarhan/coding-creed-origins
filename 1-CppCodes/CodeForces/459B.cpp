#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

#define ll int64_t

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);

class nCr{
private:
    ll n,r;
    ll **dp;
public:
    ll getDpIJ(int i, int j){ return dp[i][j];   }
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

    int n;
    ll *a;

    cin>>n;
    a = new ll[n+1];

    for(int i=0; i<n; i++){ cin>>a[i];  }
    sort(a,a+n);

    ll minimus = a[0]; ll maximus = a[n-1];
    ll d = maximus-minimus;
    ll numOfMinimus=0, numOfMaximus=0;
    ll m=0;
    for(int i=0; i<n; i++){
        if(a[i] == minimus){    numOfMinimus++; }
        else{   break; }
    }

    if(minimus!=maximus){
        for(int i=n-1; i>=0; i--){
            if(a[i] == maximus){    numOfMaximus++; }
            else{   break; }
        }
        m = (numOfMaximus*numOfMinimus);   
    }else{
       nCr ncr(n,2);
       m = ncr.getDpIJ(n,2);
    }
    cout<<d<<" "<<m<<"\n";
    if(!a)delete[] a;
    return 0;
}
