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
int **gf;
vector<int> p;
int *parent;
int src, dest;
int maxflow = 0;

bool bfs(){
    bool b = false;
    bool *isvisited;
    isvisited = new bool[n+1];
    for(int i=0; i<=n; i++){    isvisited[i] = false; }
    queue<int> q;
    q.push(src);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        isvisited[u] = true;
        for(int i=1; i<=n; i++){
            
            if(gf[u][i]!=-1){
                int v = gf[u][i];
                if(!isvisited[v]){
                    parent[v] = u;
                    q.push(v);
                    if(v == dest){  b = true; break; }
                }
            }
        }
    }


    if(!isvisited) delete[] isvisited;
    return b;
}

void findAugmentedPath(){ 
    int u = dest;
    while(u!=0){
        p.push_back(u);
        u = parent[u];
    }
}
void FordFulkersonAlgo(){
    while(bfs()){
        findAugmentedPath();
        int u,v,minimus;
        minimus = INT_MAX;
        
        for(int i=p.size()-1; i>=1; i--){
            u = p[i-1];
            v = p[i];
            minimus = min(minimus, gf[u][v]);
        }
    for(int i=p.size()-1; i>=1; i--){
            u = p[i-1];
            v = p[i];
            gf[u][v] = gf[u][v] - minimus;
            gf[v][u] = gf[v][u] + minimus;
            maxflow += minimus;
        }
    }
}

void printer(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout<<gf[i][j]<<" ";
        }cout<<"\n";
    }
}

int start(int argc=0, char const *argv[]=NULL)
{
	/* code */
  /* Soln soln */
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  
    cin>>n>>m;
    cin>>src>>dest;
    gf = new int*[n+1];
    parent = new int[n+1];
    for(int i=0; i<=n; i++){    parent[i] = 0; }
    for(int i=0; i<=n; i++){    gf[i]=new int[n+1]; }
    int a,b,c;
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){    gf[i][j] = -1;  }
    }
    for(int i=0; i<m; i++){
        cin>>a>>b>>c;
        gf[a][b] = c;
        gf[b][a] = 0;
    }

    cout<<"before\n";
    printer();
    FordFulkersonAlgo();
    cout<<"after\n";
    
    cout<<"maxflow = "<<maxflow<<"\n";
    printer();
    for(int i=0; i<=n; i++){    delete[] gf[i]; }
    delete[] gf;
	return 0;
}

bool myAssert(bool b){
    if(b){  cout<<"PASSED!\n";    }
    else cout<<"FAILED\n";  
}

void testDrivenDevelopment(){

}


int main(int argc, char const *argv[]){
    start();
    //testDrivenDevelopment();
    return 0;
}
