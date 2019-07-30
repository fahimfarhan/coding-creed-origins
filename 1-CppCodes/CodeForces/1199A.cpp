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

    ll  n,x,y, res;
    cin>>n>>x>>y;

    ll a[n+1];
    for(int i=1; i<=n; i++){    cin>>a[i];  }

    bool b=0;
    ll d=0;
    for(int i=1; i<=n; i++){
        d = i;
        b = true;
        for(int j=d-x; j<=d+y; j++){
            if( (j<1) || (j>n) ){   continue;   }
            if(a[d]>a[j]){  b=false; break; }
        }
        if(b){ res = d; break;}
    }

    cout<<res<<"\n";

    return 0;
}