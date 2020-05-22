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

int main(int argc, char const *argv[])
{
    /* code */
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    /*
    cout << num1 << endl;
    */
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,k, x0, y0, x1,y1;
    double d=0, temp=0;
    cin>>n>>k;
    cin>>x0>>y0;
    n--;
    while(n--){
        cin>>x1>>y1;
        temp = (x1-x0)*(x1-x0) + (y1-y0)*(y1-y0);
        temp = sqrt(temp);
        d+=temp;
        x0=x1; y0=y1;
    }

    d = d*k/50;
    cout << setprecision(12);
    cout<<d<<"\n";


    return 0;
}
