#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

typedef int ll;
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

    ll n,m,a,b,x,y; bool flag, *num;

    cin>>n;
    cin>>a;
    cin>>b;

    flag = false;
    num = new bool[n+1];

    for(int i=0; i<=n; i++){    num[i]=0; }
    for(int i=0; i<=n; i+=b){   num[i]=1; }

    ll ul_a = 1+n/a;
    for(ll i=0; i<=ul_a; i++){
        m = n - a*i;
        if(m>=0){
            if(num[m]){
                x = i;
                y = m/b;
                flag = true;
            }
        }
    }

    if(!flag){  cout<<"NO\n";   }
    else{
        cout<<"YES\n";
        cout<<x<<" "<<y<<"\n";
    }

    delete[] num;

    return 0;
}
