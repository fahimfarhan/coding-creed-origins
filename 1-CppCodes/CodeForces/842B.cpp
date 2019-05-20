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


// int n,m;
vector<int> *g;
bool *isvisited;

double r,d,n,x,y,z, tempdis, minimus, maximus;
int res = 0;


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

    cin>>r>>d;
    d = r-d;
    cin>>n;
    while(n--){
        cin>>x>>y>>z;

        tempdis = x*x + y*y;
        tempdis = sqrt(tempdis);

        minimus = tempdis-z; 
        maximus = tempdis+z;

        if( (minimus>=d) && (maximus <=r) ){
            res++;
        }
    }

    cout<<res<<"\n";
    return 0;
}