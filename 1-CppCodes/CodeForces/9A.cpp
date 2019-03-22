#include<bits/stdc++.h>
using namespace std;

int n,d;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n>>d;
    n = max(n,d);
    n= (6-n+1);
    d = 6;
    d = __gcd(n,d);
    n=n/d;
    d=6/d;
    cout<<n<<"/"<<d<<"\n";
    return 0;
}
