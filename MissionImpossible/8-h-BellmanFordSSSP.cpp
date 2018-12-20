#include <bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d",&x)
#define sf(x) scanf("%f",&x)

#define pi(x) printf("%d\n",x)
#define pf(x) printf("%.4f\n",x)

#define ll long long int

#define sll(x) scanf("%I64d",&x);
#define pll(x) printf("%-I64d\n",x);

int n,m;
vector< int > *g;
bool *isvisited;
int *weight;
map< int, pair<int, int> > E;
int *dis;
int src;

bool BellmanFord(){
    src = 1;

    // INIT SINGLE-SOURCE
    for(int i=0; i<=n; i++){    dis[i]=INT_MAX; }
    dis[src] = 0;

    // RELAXATION
    int u,v,w;
    for(int k=1; k<=n-1; k++){
            
            for(int i=1; i<=m; i++){
                u=E[i].first; v = E[i].second; w = weight[i];
                if( dis[v] > dis[u]+w ){
                    dis[v] = dis[u]+w;
                } 
            }
    }

    for(int i=1; i<=m; i++){
        u=E[i].first; v = E[i].second; w = weight[i];
        if( dis[v] > dis[u]+w ){
            return false;//dis[v] = dis[u]+w;
        }
    }

    return true;
    
}

int main(int argc, char const *argv[])
{
	/* code */
  /* Soln soln */
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    //g  = new vector< int >[n+10];
    //isvisited = new bool[n+10];
    dis = new int[n+10];
    weight = new int[n+10];
    //cout<<"ok0\n";
    for(int i=0; i<=n; i++){    dis[i] = INT_MAX;  }
    int a,b,c;
    //cout<<"ok01\n";
    for(int i=1; i<=m; i++){
        cin>>a>>b>>c;
        //g[a].push_back(b);
        //g[b].push_back(a);
      //  cout<<"here "<<i<<"\n";
        pair<int, int> p(a,b);
        E[i] = p;
        weight[i] = c;
    }
    //cout<<"ok1"<<"\n";
    cout<<BellmanFord()<<"\n";
    try{
        //delete[] g;
        delete[] dis;
        //delete[] isvisited;
        delete[] weight;
    }catch(exception& x){
        cout<<"FUCK!";
        cout<<x.what()<<"\n";
    }
    
	return 0;
}
