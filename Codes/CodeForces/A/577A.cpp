#include <bits/stdc++.h>
using namespace std;
#define MODULO 1e9+7
#define PI 2*acos(0)

#define ll long long int

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

    ll n,x,ans;
    ans = 0;

    cin>>n>>x;
    ll temp;
    for(int i=1; i<=n; i++){
        temp = x/i;
        if( ((temp*i) == x) && (temp<=n) ){    ans++;   }
    }

    cout<<ans<<"\n";


    
    return 0;
}
