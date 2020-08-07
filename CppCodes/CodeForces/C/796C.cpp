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

int n,m,maximus,result, *a;
int total_max_count, total_max_minus_1_count; 

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
    m=n-1;

    a = new int[n+1];
    g = new vector<int>[n+1];

    maximus = INT_MIN;
    for(int i=1; i<=n; i++){    cin>>a[i]; maximus = max(a[i], maximus); }

    total_max_count=0; total_max_minus_1_count=0;
    for(int i=1; i<=n; i++){
        if(a[i] == maximus){    total_max_count++; }
        if(a[i] == (maximus-1) ){    total_max_minus_1_count++; }
    }


    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v); g[v].push_back(u);
    }

    
    result = INT_MAX;
    for(int i=1; i<=n; i++){
        int u=0,v=0,k1=0, k2=0;
        u = i;

        for(int j=0; j<g[u].size(); j++){
            v = g[u][j];
            if(a[v] == maximus ){   k1++; }
            if(a[v] == (maximus-1) ){   k2++; }
        }

        if(a[i]==maximus){  k1++; }
        if(a[i]==maximus-1){  k2++; }

        int x = a[u];
        if(k1 > 0){ x = max(x, maximus+1); }
        //if(k2 > 0){ x = max(x, maximus-1+1);    }

        if(total_max_count > k1 ){  x = max(x, maximus+2); }
        if(total_max_minus_1_count > k2 ){  x = max(x, maximus-1+2);    }

        result = min(result, x);
    }

    cout<<result<<"\n";

    delete[] g;
    delete[] a;
    return 0;
}
