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

    int n,m,h, l,r,x;

    int *a;
    cin>>n>>h>>m;

    a = new int[n+1];
    for(int i=01; i<=n; i++){   a[i]=h; }
    for(int i=0; i<m; i++){
        cin>>l>>r>>x;
        for(int j=l; j<=r; j++){    a[j]=min(a[j],x);   }
    }

    ll ans=0;
    for(int i=1; i<=n; i++){    ans+=(a[i]*a[i]); }

    cout<<ans<<"\n";
    delete[] a;

    
    return 0;
}
