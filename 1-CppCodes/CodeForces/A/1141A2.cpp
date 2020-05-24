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

    int n,m,c,d,count;

    count = 0;
    cin>>n>>m;
    if(m>n){    n=n^m; m=n^m; n=n^m;    }
    // so we have n>m 
    if( (n%m) != 0 ){  cout<<"-1\n";   }
    else{
        d = n/m;

        while( (d&1) == 0 ){    d=d>>1; count++; }
        while( (d%3) == 0 ){    d=d/3;  count++; }

        if(d==1){cout<<count<<"\n";    }
        else{   cout<<"-1\n";   }  
    }
    return 0;
}
/*
    int     -2147483648 2147483647
    short   -32768      32767
*/