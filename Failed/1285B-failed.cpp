/* Author : Qazi Fahim Farhan (@fahimfarhan) */
/* May the CodeForces be with you! */
      // std::setprecision

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
ll t, n, *a, *dp;
    ll maximus1, maximus2;
    int negCount;
    
void MSi(){
    // base case 
    dp[0] = 0;
    for(int i=0; i<n; i++){    dp[i+1] = max(dp[i]+a[i], a[i]);    }

    maximus2 = INT_MIN;
    for(int i=1; i<=n; i++){   // cout<<dp[i]<<" ";
      maximus2 = max(maximus2, dp[i]);      }
    //cout<<"\n";

    //cout<<maximus2<<"\n";
}


int main(int argc, char const *argv[])
{
    /* code */
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    /*
    std::cout << std::fixed;
    std::cout << std::setprecision(10);
    cout << num1 << endl;
    */
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        cin>>n;
        maximus1 = 0;
        maximus2 = INT_MIN;
        a = new ll[n+1];
        dp = new ll[n+1];
        for(int i=0; i<n; i++){
            cin>>a[i];
            maximus1+=a[i];
            if(a[i]<0){ negCount++; }
        }
        if(negCount==0){
            cout<<"YES\n";
        }else{
            MSi();
            if(maximus1>maximus2){  cout<<"YES\n";  }
            else{   cout<<"NO\n";   }
        }
        delete[] a;
        delete[] dp;
    }


    return 0;
}

