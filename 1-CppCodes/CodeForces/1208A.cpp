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

    ll T, a, b, n, f[3];
    ll one = 1;
    cin>>T;
    while(T--){
        cin>>a>>b>>n;
        f[0] = a; f[1] = b; f[2] = a^b;
        n = n%3;
        cout<<f[n]<<"\n";
        /*
        ll f[n+2];
        f[0] = a; f[1] = b;
        for(int i=2; i<=n; i++){    f[i] = f[i-1]^f[i-2]; cout<<f[i]<<" ";   }
        */
       //if( (n&one) == 1){  cout<<b<<"\n";  }
       //else {   cout<<a<<"\n";  }
    }



    return 0;
}