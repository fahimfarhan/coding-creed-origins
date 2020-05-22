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
    ll a,b,x,p,y,j,mygcd;
    cin>>n>>m;
    cin>>a>>b;
    y = a;
    mygcd = abs(a-b);
    a = b;
    for(int i=2; i<n; i++){
        cin>>b;
        x = abs(a-b);
        mygcd = __gcd(mygcd,x);
        a = b;
    }
    //cout<<mygcd<<"\n";
    bool b123 = false; 
    for(int i=0; i<m; i++){
        cin>>p;
        if( (mygcd%p) == 0){
            b123 = true; 
            j = i+1;
            break;
        }
    }

    if(b123){
        cout<<"YES\n";
        cout<<y<<" "<<j<<"\n";
    }else{
        cout<<"NO\n";
    }

    return 0;
}
