#include <bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d",&x)
#define sf(x) scanf("%f",&x)

#define pi(x) printf("%d\n",x)
#define pf(x) printf("%.4f\n",x)

#define ll long long int

#define sll(x) scanf("%I64d",&x);
#define pll(x) printf("%-I64d\n",x);

	int index1,n;
    int *depth;
    bool *isvisited;
    ll ans, minimus,d, *a;
    vector<ll> *g;
    queue<ll> q;

    vector<int> candidates;
void bfs(){
    
    q.push(index1);
    // d = 0;
    depth[index1] = 0;
    while(!q.empty()){
            int u = q.front();
            q.pop();
            isvisited[u] = true;
            
            for(int i=0; i<g[u].size(); i++){
            int v = g[u][i];
            if(!isvisited[v]){
                depth[v] = depth[u]+1;
                ans += depth[v]*a[v];
                q.push(v);
            }
            
        }
    }

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
    minimus = INT_MAX;
    cin>>n;
    d = 0;
    a = new ll[n+1];
    g = new vector<ll>[n+1];
    depth = new int[n+1];
    isvisited = new bool[n+1];
    for(int i=0; i<=n; i++){    isvisited[i] = false; }
    for(int i=1; i<=n; i++){
        cin>>a[i];
        //minimus = min(minimus, a[i]);
        //if(minimus>a[i]){   minimus = a[i]; index1 = i; }
    }

    for(int i=1; i<=n; i++){    if(a[i] == minimus) candidates.push_back(i); }
    int u,v;
    for(int i=0; i<n-1; i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    ll final_ans = 0;
    for(int i=0; i<candidates.size(); i++){
         for(int i=0; i<=n; i++){    depth[i]=0;     }
    
        ans = 0;
        index1 = candidates[i];
        bfs();
        final_ans = max(final_ans, ans);
    }
     
    cout<<final_ans<<"\n";

    delete[] a;
    delete[] isvisited;
    delete[] g;
    delete[] depth;
	return 0;
}
