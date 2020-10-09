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
int n, m,m1,m2, minimus, maximus, result, *a;

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

    maximus = INT_MIN;
    
    for(int i=1; i<=n;  i++){   cin>>a[i]; maximus = max(maximus, a[i]);    }
    
    for(int i=0; i<m; i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y); g[y].push_back(x);
    }

    // --------------------
    m1=0; m2=0;
    for(int i=1; i<=n; i++){
        if(a[i] == maximus ){  m1++; }
        if(a[i] == (maximus-1) ){   m2++; }
    }


    result = INT_MAX;
    for(int i=1; i<=n; i++){
        int k1=0, k2=0;
        for(int j=0; j<g[i].size(); j++){
            if(a[g[i][j]] == maximus) k1++;
            if(a[g[i][j]] == (maximus-1)) k2++;
        }    
        int x = a[i];
        if(k1>0){   x = max(x, maximus+1); }
        if(a[i]==maximus){  k1++; }
        if(m1>k1){ x = max(x, maximus+2);  }
        if(a[i]==(maximus-1)){  k2++; }
        if(m2>k2){  x = max(x, maximus-1+2);  }

        result = min(result,x);        
    }

    cout<<result<<"\n";

    delete[] g;
    delete[] a;
    return 0;
}
