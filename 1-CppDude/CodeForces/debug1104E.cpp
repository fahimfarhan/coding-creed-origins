#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

#define ll long long int

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


int n,m,k;
vector<int> *g;
vector<int> path; 
vector<vector<int> > cycle;
bool *isvisited;
int flag;
// if flag == 0 => -1, flag == 1 => path found! , flag == 2 => cycle

void dfs(int u){
    isvisited[u] = true;
    path.push_back(u);
    if(path.size() >= (n/k) ){
        flag = 1;
        return;
        //exit(0);
    }else{
            int v;
        for(int i=0; i<g[u].size(); i++){
            v = g[u][i];
            if(!isvisited[v]){  dfs(v); }
        
        }path.pop_back();
    }

    
}

void findPath(){
    for(int i=0; i<=n; i++){
        isvisited[i] = false;
    }
    for(int i=1; i<=n; i++){
        if(flag == 1){  break; }
        if(!isvisited[i]){
            dfs(i);
        }
    }
}

void dfs_visit(int u){
    path.push_back(u);
    isvisited[u] = true;

    cout<<"debug 56\n";
    for(int i=0; i<path.size(); i++){
        cout<<path[i]<<" ";
    }cout<<"\n";

    int v;
    for(int i=0; i<g[u].size(); i++){
        v = g[u][i];
        if(!isvisited[v]){  dfs_visit(v);   }
        else{
            // detected a cycle!!!
            if( (path.size() > 3) && (path.size()%3 !=0) ){
                
                cycle.push_back(path);
                //flag = 2;
                //return;
            }
            
        }
    }
    path.pop_back();

}

void findCycle(){

    for(int i=0; i<=n; i++){
        isvisited[i] = false;
    }
    for(int i=1; i<=n; i++){
        path.clear();

        if(cycle.size()>=k){ flag = 2;  }
        
        if(!isvisited[i]){
            dfs_visit(i);
        }
        
    }
    
}


    
int main(int argc, char const *argv[])
{
	/* code */
  /* Soln soln */
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  /*
  cout << setprecision(8);
  cout << num1 << endl;
  */
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

    cin>>n>>m>>k;
    g = new vector<int>[n+1];
    isvisited = new bool[n+1];

    int a,b;
    for(int i=0; i<m; i++){
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(int i=1; i<=n; i++){
        cout<<i<<" --> ";
        for(int j=0; j<g[i].size(); j++){
            cout<<g[i][j]<<" ";
        }cout<<"\n";
    }

    flag = 0;
    // solve path
    findPath();
    if(path.size() >= ceil(n/k) ){
        flag = 1;
        cout<<"PATH\n";
        cout<<path.size()<<"\n";
        for(int i=0; i<path.size(); i++){
            cout<<path[i]<<" ";
        }cout<<"\n";
        //return;
        //exit(0);
    }
    //solve cycle
    if(flag!=1){
        findCycle();
    }
    if(flag == 2){
        cout<<"CYCLES\n";
        for(int i=0; i<cycle.size(); i++){
            cout<<cycle[i].size()<<"\n";
            for(int j=0; j<cycle[i].size(); j++){
                cout<<cycle[i][j]<<" ";
            }cout<<"\n";
        }
    }

    // -1
    if(flag == 0){
        cout<<"-1\n";
    }

  delete[] g;
  delete[] isvisited;
  return 0;
}

