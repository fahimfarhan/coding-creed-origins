#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)
#define ll long long
ll MODULO=1e9+7;

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


// int n,m;
vector< int > *g;
bool *isvisited;

int n,m,k;
ll p, sumP_k, n_k;



ll mymodulo(ll in){
    ll out = in;
    while(out>=MODULO){ out-=MODULO;    }
    return out;   
}

ll myPow(ll a, ll b){
    if(b==0){   return 1;   }
    if(b==1){   return a;   }
    ll ret=1;
    ll b1 = b>>1;
    ret = myPow(a,b1)%MODULO;
    //ret = mymodulo(ret);
    ret=ret*ret;
    ret = (ret)%MODULO;
    if( (b&1) == 1){
        ret = (ret*a)%MODULO;
    }
    return ret;
}

void dfs_visit(int u){
    p++;
    isvisited[u]=true;
    int v = 0,w=0, size = g[u].size();
    for(int i=0; i<size; i++){
        v = g[u][i];
        //w = g[u][i].second;

        if( (!isvisited[v]) ){
            dfs_visit(v);
        }
    }
}

void dfs(){
    for(int i=0; i<=n; i++){    isvisited[i]=false;    }

    for(int i=1; i<=n; i++){
        if(!isvisited[i]){
            p=0;
            dfs_visit(i);
            sumP_k += myPow(p,k);
            while(sumP_k>=MODULO){  sumP_k-=MODULO; }
        }
    }

}

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

    cin>>n>>k;
    m=n-1;
    g = new vector< int >[n+1];
    isvisited = new bool[n+1];
    int a,b,x;

    for(int i=0; i<m; i++){
        cin>>a>>b>>x;
        if(x==0){
            g[a].push_back(b);
            g[b].push_back(a);
        }
    }

    dfs();
    n_k = myPow(n,k);
    ll ans = n_k - sumP_k+MODULO;
    while(ans>=MODULO){  ans-=MODULO;    }

    cout<<ans<<"\n";
    
    if(!g)delete[] g;
    if(!isvisited)delete[] isvisited;
    return 0;
}