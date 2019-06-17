#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

typedef int64_t ll;
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

    ll x,y,z;
    ll n=0, r=0;

    cin>>x>>y>>z;

    n = (x+y)/z;

    if(n == ( x/z + y/z )){
        cout<<n<<" 0\n";
    }else{
        x = x%z; y=y%z;

        if(y>x){    swap(x,y);  }

        y = z - x;
        cout<<n<<" "<<y<<"\n";
    }



    return 0;
}
