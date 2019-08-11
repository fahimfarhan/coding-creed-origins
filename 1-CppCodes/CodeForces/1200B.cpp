/* Author : Qazi Fahim Farhan (@fahimfarhan) */
/* May the CodeForces be with you! */
#include <bits/stdc++.h>

using namespace std;

#define PI 2*acos(0)

//typedef long long int ll;
 #define ll int64_t
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

    ll T;

    ll n,m,k, hreq, have = 0;

    cin>>T;

    while(T--){
        cin>>n>>m>>k;
        have = m;
        ll h[n+1];
        for(int i=1; i<=n; i++){    cin>>h[i];  }

        bool b = true;
        for(int i=1; i<n; i++){
            have = h[i]+have;

            hreq = h[i+1]-k;
            hreq = max(hreq, (ll)0);
            if(have < hreq ){   b = false; break; }
            else{
                have = have - hreq;
            }
        }

        if(b){  cout<<"YES\n";  }
        else{   cout<<"NO\n";   }
    }


    return 0;
}