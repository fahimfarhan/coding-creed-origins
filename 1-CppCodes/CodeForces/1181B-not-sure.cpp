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


// int n,m;s
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

    int l,n, x,y;
    cin>>l;
    cin>>n;

    if( (l&1) == 0){
        int l1=l>>1;
        int m = pow(10,l1);

        x = n/m;
        y = n%m;

        cout<<(x+y)<<"\n";
    }else{
        int l1 = l>>1;
        int l2 = l-l1;

        int m = pow(10,l1);
        x = n/m;
        y = n%m;

        int sum1=0, sum2=0;

        sum1 = x+y;

        m = pow(10,l2);
        x = n/m;
        y = n%m;

        sum2 = x+y;

        if(sum1<sum2){  cout<<sum1<<"\n"; }
        else cout<<sum2<<"\n";


    }

    return 0;
}
