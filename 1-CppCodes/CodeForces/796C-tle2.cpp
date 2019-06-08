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

int n,m,*a;
int minimus, maximus;

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

    cin>>n;
    m = n-1;

    a = new int[n+1];
    g = new vector<int>[n+1];
    isvisited = new bool[n+1];

    for(int i=1; i<=n; i++){    cin>>a[i]; a[i]+=2;     }

    int x, y;
    for(int i=0; i<m; i++){
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }


    minimus = INT_MAX;
    for(int i=1; i<=n; i++){
        a[i]-=2;
        for(int j=0; j<g[i].size(); j++){
            int v = g[i][j];
            a[v]-=1;
        }

        maximus = INT_MIN;
        for(int i=1; i<=n; i++){
            maximus = max(maximus, a[i]);
        }

        for(int j=0; j<g[i].size(); j++){
            int v = g[i][j];
            a[v]+=1;
        }
        a[i]+=2;

        minimus = min(minimus, maximus);
    }

    cout<<minimus<<"\n";
    
    return 0;
}
