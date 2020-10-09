/* Author : Qazi Fahim Farhan (@fahimfarhan) */
/* May the CodeForces be with you! */
#include <bits/stdc++.h>

using namespace std;

#define PI 2*acos(0)

//typedef long long int ll;
 #define ll int
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

    ll n, a, one=1;

    cin>>n;

    if(n&one==one){
        cout<<"YES\n";
        for(int i=1; i<=n; i++){ cout<<((i<<1)-(i&one))<<" ";    }
        for(int i=1; i<=n; i++){ cout<<((i<<1)-((i-1)&one))<<" ";    }
        cout<<"\n";
    }else{  cout<<"NO\n";   }

    return 0;
}