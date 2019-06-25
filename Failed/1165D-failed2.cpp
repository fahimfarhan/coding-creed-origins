#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

#define ll long long int
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
    vector<ll> u,v;
        
    ll n,T;
    ll x,d,a,b, minimus, maximus;
    cin>>T;
    while(T--){
        cin>>n;

        for(ll i=0; i<n; i++){
            cin>>x;
            u.push_back(x);
            //if(i==0){   minimus = x; maximus = x;   }
            // else{   maximus = max(maximus, x);  minimus = min(minimus,x);   }
        }
        sort(u.begin(), u.end());
        minimus = u[0]; maximus = u[n-1];
        d = minimus*maximus;

        for(ll i=2; i*i<=d; i++){
            if(d%i == 0){   
                //v.push_back(i); 
                a = i; b = d/i;
                v.push_back(a);    
                if(b != a){ v.push_back(b);  }
            }
        }

        sort(v.begin(), v.end());
        if(v == u){    cout<<d<<"\n";   }
        else{  cout<<"-1\n";   }
    }

    return 0;
}
