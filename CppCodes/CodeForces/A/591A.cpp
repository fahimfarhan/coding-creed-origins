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
    

    //cout << num1 << endl;
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    double l,p,q,x;
    cin>>l;
    cin>>p;
    cin>>q;

    x = 1.0*l*p/(p+q);

    cout << setprecision(8);
    cout<<x<<"\n";
    
    return 0;
}
