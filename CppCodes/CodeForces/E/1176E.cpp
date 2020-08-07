#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

#define NOT_VISITED 0
const int RED =   1;
const int BLUE =  ~RED;

typedef long long int ll;
// #define ll long long int
// other popular ones=> int64_t, uint64_t => use for 10^18
ll MODULO = 1e9+7;

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


// int n,m;s
vector<int> *g;
int *isvisited;

int t,n,m;

void bfs(int start = 1){

    int blueCount=0, redCount=0;
    queue<int> q;
    q.push(start);
    isvisited[start] = BLUE;
    blueCount++;

    int u,v, parentColor, childColor;

    while(!q.empty()){
        u = q.front();
        q.pop();

        for(int i=0; i<g[u].size(); i++){
            v = g[u][i];
            if(isvisited[v]==NOT_VISITED){
                parentColor = isvisited[u];
                childColor = ~parentColor;

                isvisited[v] = childColor;
                q.push(v);

                if(childColor == BLUE){ blueCount++; }
                else{   redCount++; }
            }
        }    
    }
    int k = (n>>1);
    if(redCount<=k){
        cout<<redCount<<"\n";
        for(int i=1; i<=n; i++){
            if(isvisited[i] == RED ){ cout<<i<<" "; }
        }cout<<"\n";
    }else{
        cout<<blueCount<<"\n";
        for(int i=1; i<=n; i++){
            if(isvisited[i] == BLUE ){ cout<<i<<" "; }
        }cout<<"\n";        
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

    cin>>t;
    while(t--){
        cin>>n>>m;
        g = new vector<int>[n+1];
        isvisited = new int[n+1];

        for(int i=0; i<=n; i++){    isvisited[i] = 0; }

        int u,v;
        for(int i=0; i<m; i++){ 
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        /*int maximus = 0, start = 0;
        for(int i=1; i<=n; i++){    
            if(g[i].size()>maximus){    maximus = g[i].size(); start = i; }
        }*/

        bfs(1);

        if(!isvisited)delete[] isvisited;
        if(!g)delete[] g;
    }

    return 0;
}
