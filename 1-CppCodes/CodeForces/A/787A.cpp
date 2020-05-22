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

bool num[10000]={0};

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

    int a,b,c,d;
    cin>>a>>b;
    cin>>c>>d;

    for(int i=d; i<10000; i+=c){ num[i]=1; }
    for(int i=b; i<10000; i+=a ){
        if(num[i]){
            cout<<i<<"\n";
            exit(0);
        }
    }

    cout<<"-1\n";
    return 0;
}
