#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

#define ll int64_t
// other popular ones=> int64_t, uint64_t => use for 10^18
ll MODULO = 1e9+7;

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


// int n,m;
vector<int> *g;
bool *isvisited;

int n,m;
ll *x, *p;

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


    cin>>n>>m;
    x = new ll[n+1];   p = new ll[m+1];

    for(int i=0; i<n; i++){ cin>>x[i];  }
    for(int i=0; i<m; i++){ cin>>p[i];  }

    ll a,b,mygcd;
    a = abs(x[0]-x[1]);
    mygcd = a; 
    for(int i=2; i<n; i++){
        b = abs(x[i]-x[i-1]);
        mygcd = __gcd(mygcd,b);
        // a = b;
    }

    bool b123 = false;
    ll Y, J; 
    for(int i=0; i<m; i++){
        if(  (mygcd%p[i]==0) ){
            b123 = true; J = i+1; break;
        }
    }

    if(b123){
        Y = x[0];
        cout<<"YES\n";
        cout<<Y<<" "<<J<<"\n";
    }else{
        cout<<"NO\n";
    }


    delete[] x; delete[] p;
    return 0;
}
