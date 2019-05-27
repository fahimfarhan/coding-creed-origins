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

    ll n,k;
    cin>>n>>k;

    ll a[3] = {2,5,8};

    ll minimus = 0;
    for(int i=0; i<3; i++){
        a[i] = a[i]*n;
        minimus += a[i]/k;
        if(a[i]%k!=0){  minimus+=1; }
    }

    cout<<minimus<<"\n";

    return 0;
}
