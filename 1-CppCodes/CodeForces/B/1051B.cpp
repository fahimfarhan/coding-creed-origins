#include <bits/stdc++.h>
using namespace std;
#define MODULO 1e9+7
#define PI 2*acos(0)

#define ll uint64_t

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

    ll l,r;
    cin>>l>>r;
    cout<<"YES\n";
    for(ll i=l; i<=r; i+=2){
        cout<<i<<" "<<(i+1)<<"\n";
    }
    return 0;
}
