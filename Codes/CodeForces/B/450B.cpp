#include <bits/stdc++.h>
using namespace std;
#define PI 2*acos(0)

#define ll long long int
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

    ll x,y,n;
    ll a[6];
    cin>>x>>y;
    cin>>n;
    
    x = (x)%MODULO;
    y = (y)%MODULO;
    
    a[0]=x; a[1]=y; a[2]=y-x; a[3]=-x; a[4]=-y; a[5]=x-y;
    for(int i=0; i<6; i++){
        a[i]=(a[i])%MODULO;
        if(a[i]<0){ a[i]+=MODULO; }
        //cerr<<a[i]<<" ";
    }
    n=n-1;
    n=n%6;

    cout<<a[(int)n]<<"\n";

    
    return 0;
}
