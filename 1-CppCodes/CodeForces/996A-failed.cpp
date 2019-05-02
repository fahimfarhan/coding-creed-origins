#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

#define ll long long int

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


// int n,m;
vector<int> *g;
bool *isvisited;

int coin[5] = {1,5,10,20,100};
int *dp;

int recursion(int m){
    if(m<0){    return 0;   }
    int ret=0;
    if(dp[m]!=INT_MAX)  {   return dp[m];   }
    else{   
        ret = INT_MAX;
        for(int i=0; i<5; i++){
            ret = min( ret , (m-coin[i]) );
        }
        ret=ret+1;
        dp[m]=min(dp[m],ret);
        return dp[m];
    }
    return ret;
}
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
    cin>>n;
    dp = new int[n+1];
    for(int i=0; i<=n; i++){    dp[i]=INT_MAX;  }
    dp[0]=0; dp[1]=1;

    cout<<recursion(n)<<"\n";

    delete[] dp;
    
    return 0;
}
