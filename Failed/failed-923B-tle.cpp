#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

typedef long long int ll;
// #define ll long long int
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

    int N;
    ll ans,*V, *T;

    cin>>N;
    V = new ll[N+1]; T = new ll[N+1];

    for(int i=0; i<N; i++){    cin>>V[i];  }
    for(int i=0; i<N; i++){    cin>>T[i];  }


    for(int i=0; i<N; i++){
        ans = 0;
        for(int j=0; j<=i; j++){
            if(V[j]> (ll)0){     ans+=min(V[j], T[i]); V[j] = max( (ll)0, (V[j]-T[i]) );   }
        }
        cout<<ans<<" ";
    }cout<<"\n";

    delete[] V; delete[] T;
    return 0;
}
