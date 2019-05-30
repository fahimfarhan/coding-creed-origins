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

int n;
ll *v, *t, *cnt, *m;

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

    v = new ll[n+2];
    t = new ll[n+2]; // cumulative frequency
    cnt = new ll[n+2];
    m = new ll[n+2];

    v[0] = 0; t[0] = 0;
    v[n+1] = 0; t[n+1] = 0;
    for(int i=0; i<n+2; i++){  v[i] = 0; m[i]=0; t[i]=0; cnt[i]=0;    }

    for(int i=1; i<=n; i++){    cin>>v[i];  }
    for(int i=1; i<=n; i++){    cin>>t[i]; t[i] = t[i]+t[i-1];   }

    int k = 0;
    for(int i=1; i<=n; i++){
        k = lower_bound(t+i, t+n+1, (t[i-1]+v[i]) ) - t;
        cnt[i]++;
        if(k<=n){
            m[k] = m[k]+v[i]-(t[k-1] - t[i-1]);
            cnt[k]--;
        }
    }

    for(int i=2; i<=n; i++){    cnt[i]+=cnt[i-1];   }

    ll res = 0;
    for(int i=1; i<=n; i++){
        res = (cnt[i]*(t[i]-t[i-1]) + m[i]);
        cout<<res<<" ";
    }cout<<"\n";

    

    delete[] v;
    delete[] t;
    delete[] cnt;
    delete[] m;
    return 0;
}
