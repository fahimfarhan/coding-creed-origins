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

    int n,m;
    ll aodd=0, aeven=0, bodd=0, beven=0;

    cin>>n>>m;

    ll input;
    for(int i=0; i<n; i++){
        cin>>input;
        if( (input&1) == 1){    aodd++; }
        else{   aeven++; }
    }

    for(int i=0; i<m; i++){
        cin>>input;
        if( (input&1) == 1){    bodd++; }
        else{   beven++; }
    }

    ll ans=0;
    ans = min(aodd,beven) + min(aeven, bodd);
    cout<<ans<<"\n";
    return 0;
}
