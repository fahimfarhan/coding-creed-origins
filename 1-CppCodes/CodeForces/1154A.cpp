#include <bits/stdc++.h>
using namespace std;

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

    ll x[4],a,b,c;

    for(int i=0; i<4; i++){ cin>>x[i];  }

    sort(x,x+4);

    a = x[3] - x[2];
    b = x[1] - a;
    c = x[0] - a;
    cout<<a<<" "<<b<<" "<<c<<"\n";
    return 0;
}
