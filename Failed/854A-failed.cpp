#include <bits/stdc++.h>
using namespace std;
#define PI 2*acos(0)
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,a,b,mygcd;
    cin>>n;

    a=n/2;
    b=n-a;

    if(a==b){   a--; b++; }

    mygcd = __gcd(a,b);
    a=a/mygcd;
    b=b/mygcd;

    cout<<a<<" "<<b<<"\n";


    return 0;
}
