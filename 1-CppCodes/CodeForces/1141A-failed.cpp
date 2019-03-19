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


    ll n,m,c, stop, count=0;
    cin>>n>>m;
    if(n==m){   cout<<"0\n";    }
    if(n>m){
        n=n^m;
        m=n^m;
        n=n^m;
    }
    // so m>n
    count = 0;
    while(true){
        if(m<=n){   break; }
        if( (m%2) == 0 ){m=m/2; }
        else{   m=m/3; }
        count++;
        if(m<=n){   break; }
    }
    if(m==n){   cout<<count<<'\n';  }
    else{   cout<<"-1\n";   }

    return 0;
}
/*
    int     -2147483648 2147483647
    short   -32768      32767
*/