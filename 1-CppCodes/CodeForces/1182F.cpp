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

    int t;
    ll a,b,p,q, m, x, x1,x2,res;

    cin>>t;
    while(t--){
        cin>>a>>b>>p>>q;

        m = ceil(1.0*a/PI -0.5 );

        x = ceil(1.0*q/p)*(2*m+1)/2;

         x1=x-1, x2=x+1;
        
        double y,y1,y2;
        y = sin(1.0*(p/q)*(x*PI));
        y1 = sin(1.0*(p/q)*(x1*PI));
        y2 = sin(1.0*(p/q)*(x2*PI));

        if(y>y1 && y>y2){  res = x; }
        else if(y1>y2){ res = x1; }
        else{   res = x2; }

        cout<<res<<"\n";
    }





    return 0;
}
