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


// int n,m;
vector<int> *g;
bool *isvisited;

map<ll,ll> vis;
map<pair<int,int> ,int> sim;

int n;
ll a,b,x,Vx,Vy, ans = 0;

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

    cin>>n>>a>>b;
    while(n--){
        cin>>x>>Vx>>Vy;
        ans += vis[a*Vx-Vy] - sim[{Vx, Vy}];
        vis[a*Vx-Vy]++;
        sim[{Vx,Vy}]++;

    }
    ans = ans<<1;
    cout<<ans<<"\n";
    return 0;
}
