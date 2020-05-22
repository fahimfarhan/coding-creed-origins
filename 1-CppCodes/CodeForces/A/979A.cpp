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

    int64_t n;
    cin>>n;
    if(n==0){   cout<<"0\n";    exit(0);    }
    n++;

    if( (n&1) == 0){   n=n>>1; }
    cout<<n<<"\n";
    return 0;
}
/*
    int     -2147483648 2147483647
    short   -32768      32767
*/