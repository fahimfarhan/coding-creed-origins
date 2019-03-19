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

    ll l,r;
    cin>>l>>r;

    //n = 1+(r-l)/2;

    cout<<"YES\n";
    for(int i=l; i<r; i+=2){
        cout<<i<<" "<<(i+1)<<"\n";
    }

    return 0;
}
/*
    int     -2147483648 2147483647
    short   -32768      32767
*/