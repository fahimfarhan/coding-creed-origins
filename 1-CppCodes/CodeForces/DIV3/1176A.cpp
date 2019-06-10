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

    int q, ans;
    ll n;
    cin>>q;
    while(q--){
        cin>>n;
        ans = 0;
        while(n%2==0){ n=n/2; ans++; }
        while(n%3==0){ n=n/3; ans+=2; }
        while(n%5==0){ n=n/5; ans+=3; }
        
        if(n==1){   cout<<ans<<"\n"; }
        else{ cout<<"-1\n";   }
        
    }

    return 0;
}
