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

    ll *a, *b, *val;

    int n,q;
    cin>>n>>q;

    a = new ll[n+1]; b = new ll[n+1]; val = new ll[n+1];
    a[0]=0; b[0]=0; val[0]=0;
    for(int i=0; i<=n; i++){    a[i]=0; b[i]=0; val[i]=0; }
    for(int i=1; i<=n; i++){    cin>>a[i]; }
    
    int l,r;
    for(int i=0; i<q; i++){
        cin>>l>>r;
        val[l]++;
        r = r+1;
        if(r<=n){   val[r]--; }
    }

    int v = 0;
    for(int i=1; i<=n; i++){
        v=v + val[i]; 
        b[i] = v;
    }
    
    sort(a, a+n+1);
    sort(b, b+n+1);

    int64_t result = 0;
    for(int i=1; i<=n; i++){
        result = result + (a[i]*b[i]);
    }

    cout<<result<<"\n";

    return 0;
}
