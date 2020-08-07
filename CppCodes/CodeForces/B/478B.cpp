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

    ll n,m,minimus, maximus;

    cin>>n>>m;

    // maximus
    ll N = n-m+1; // n - (m-1); 
    maximus = N*(N-1);
    maximus = maximus>>1;

    // minimus 
    ll d = n/m; ll r = n%m;
    // minimus = r.d.(d+1)/2 + (m-r).d.(d-1)/2;
    minimus = r*d*(d+1) + (m-r)*d*(d-1);
    minimus = minimus>>1;

    cout<<minimus<<" "<<maximus<<"\n";
    return 0;
}
