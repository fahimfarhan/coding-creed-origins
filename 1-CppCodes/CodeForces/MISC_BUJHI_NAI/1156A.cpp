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

    int n,ans,a[101];

    cin>>n;
    for(int i=0; i<n; i++){ cin>>a[i]; }

    ans = 0;
    for(int i=1; i<n; i++){
        if( (i>1) && (a[i]==2) && (a[i-1]==1) && (a[i-2]==3) ){  ans--; }
        if(a[i]+a[i-1]==5){ cout<<"Infinite\n";   return 0; }
        ans+=a[i]+a[i-1];
    }
    
    cout<<"Finite\n";
    cout<<ans<<"\n";

    return 0;
}
