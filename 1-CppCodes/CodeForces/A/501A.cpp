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

    ll a,b,c,d;

    ll misha, vasya;

    cin>>a>>b>>c>>d;

    misha = max(3*a/10, a-a*c/250);
    vasya = max(3*b/10, b-d*b/250);

    if(misha > vasya){
        cout<<"Misha\n";
    }else if(misha < vasya){
        cout<<"Vasya\n";
    }else{
        cout<<"Tie\n";
    }

    return 0;
}
