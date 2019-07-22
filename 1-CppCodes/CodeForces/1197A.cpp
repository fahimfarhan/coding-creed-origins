#include <bits/stdc++.h>

using namespace std;

#define PI 2*acos(0)

//typedef long long int ll;
 #define ll long long int
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

    ll T, n, k;
    cin>>T;
    while(T--){
        cin>>n;
        ll a[n+1]={0};
        ll cf[n+1] = {0};
        k = 0;
        for(int i=0; i<n; i++){ cin>>a[i]; cf[a[i]]++;   }

        for(int i=n-1; i>=0; i--){  cf[i] = cf[i]+cf[i+1];  }
        
        k = n-2;

        
        while(k>0){
            if( (cf[k+1]-cf[n-1])>=2 || cf[k+1]>=2){   break; }
            else{k--;}
        }
        
        cout<<k<<"\n";
    }

    return 0;
}