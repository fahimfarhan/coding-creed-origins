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
    /* Soln soln */
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    /*
    cout << setprecision(8);
    cout << num1 << endl;
    */
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a,b,c,d;
    cin>>a>>b>>c>>d;

    double p=(1.0*a)/b; double q = (1.0*c)/d;

    double r = (1-p)*(1-q);

    double ans = p/(1-r);
    cout << setprecision(8);
    cout<<ans<<"\n"; 

    return 0;
}
/*
    int     -2147483648 2147483647
    short   -32768      32767
*/