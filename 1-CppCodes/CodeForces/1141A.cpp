#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

#define ll long long int


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

    int a,b,n,m,c,d;
    cin>>a>>b;
    n = max(a,b); m = min(a,b);

    //cout<<(m%n)<<"\n";
    if( (n%m) != 0 ){
      
        cout<<"-1\n"; return 0;
    }
    d = n/m;

    c=0;
    while( (d%2) == 0){    d=d/2; c++; }
    while( (d%3) == 0){    d=d/3; c++; }
    if(d==1){   cout<<c<<"\n";  }
    else{   cout<<"-1\n";   }
    return 0;
}
/*
    int     -2147483648 2147483647
    short   -32768      32767
*/