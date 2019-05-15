#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

typedef long long ll;
// #define ll long long int
// other popular ones=> int64_t, uint64_t => use for 10^18
ll MODULO = 1e9+7;

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


// int n,m;
vector<int> *g;
bool *isvisited;

ll a,b,d,minimus, maximus, T; 

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

    cin>>T;
    while(T--){
        ll n, *u, *v;
        cin>>n;
        u = new ll[n+1];
        v = new ll[n+1];

        minimus = INT_MAX;
        maximus = -1;

        for(ll i=0; i<n; i++){   cin>>u[i];       }

        sort(u,u+n);
        
        minimus = u[0]; maximus = u[n-1];
        
        d = minimus*maximus;
        
        ll j = 0;

        for(ll i=2; i*i<=d; i++){
            if( (d%i) == 0){
                a = i; b = d/i;
                
                if(j<n){ v[j]=a; }
                j++;
        
                if(a!=b){
                    if(j<n){v[j]=b;}
                    j++;
                }
            }
        }

        sort(v,v+n);
        
        bool b124=true;
        
        for(int i=0; i<n; i++){
            if(u[i]!=v[i]){ b124 = false; break; }
        }
        if(j>n){    b124 = false; }
        if(b124){
            cout<<d<<"\n";
        }else{  cout<<"-1\n";   }

        delete[] v;
        delete[] u;
    }

    return 0;
}
