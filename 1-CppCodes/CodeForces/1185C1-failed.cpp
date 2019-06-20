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

    int n,m,res, *cf;

    cin>>n>>m;

    cf = new int[n+2];
    cf[0]=0;
    cf[n+1]=0;

//    cin>>cf[01];
    for(int i=1; i<=n; i++){
        cin>>cf[i];
        cf[i]+=cf[i-1];
    }


    for(int i=0; i<n; i++){
        res = 0;
        if(cf[i]<m){    cout<<res<<" "; }
        else{
            int ti = cf[i]-cf[i-1];
            int temp = m-ti;
            int lb = lower_bound(cf, cf+n, temp)-cf;
            while(cf[lb]+ti > m){   lb--; }
            res = i-lb; // r-l+1 = (i-1) - lb + 1 = i-lb 
            cout<<res<<" ";
        }
    }cout<<"\n";

    delete[] cf;

    return 0;
}
