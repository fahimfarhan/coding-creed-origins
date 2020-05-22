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

    int a[6];

    for(int i=0; i<6; i++){ cin>>a[i];  }

    int A = a[0]+a[1]+a[2];

    double ans = A*A - a[0]*a[0] - a[2]*a[2] - a[4]*a[4];

    ans = ans; //*sqrt(3)/4;

    cout<<(int)ans<<"\n";

    return 0;
}
