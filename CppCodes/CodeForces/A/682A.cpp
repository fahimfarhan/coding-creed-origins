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
    /* Soln soln */
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    /*
    cout << setprecision(8);
    cout << num1 << endl;
    */
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ll ans = 0;
    int n,m;
    int r, d;

    cin>>n>>m;
    
    ll a[6], b[6];

    d = m/5;
    r=m%5;

    for(int i=0; i<5; i++){ a[i]=d;}
    for(int i=1; i<=r; i++){   a[i]++; }
    // repeat for n 

    d = n/5; r = n%5;
    for(int i=0; i<5; i++){ b[i]=d;}
    for(int i=1; i<=r; i++){   b[i]++; }
    
    ans=0;
    ans+=a[0]*b[0];

    for(int i=01; i<5; i++){
        ans+=a[i]*b[5-i];
    }

    cout<<ans<<"\n";

    return 0;
}
/*
    int     -2147483648 2147483647
    short   -32768      32767
*/