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
set<vector<int> > cycle;
vector<int> r;
        
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

    int v;
    for(int i=0; i<g[u].size(); i++){
        v = g[u][i];
        if(!isvisited[v]){  dfs_visit(v);   }
        else{
            // detected a cycle!!!
            int j = 0;
            if( (path.size() > 3) && (path.size()%3 !=0) ){
                
                if(r.size()>0){
                    
                    while(true){
                        int x = path[0];
                        int lb = lower_bound(r.begin(), r.end(), x)-r.begin();
                        if(r[lb] == x){ j++; }else{     break;    }
                    }

                }
                vector<int> temppath;
                for(int i11 = j+1; i11<path.size(); i11++){
                    temppath.push_back(path[i11]);
                }
                for(int i11=0; i11<=j; i11++){
                    temppath.push_back(path[i11]);
                }
                cycle.insert(temppath);
                
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
        if(cycle.size()>=k){ flag = 2;  }
        if(!isvisited[i]){
            //while(path.size()!=0){  path.pop_back(); }
            path.clear();
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
        /*for(int i=0; i<k; i++){
            cout<<cycle[i].size()<<"\n";
            for(int j=0; j<cycle[i].size(); j++){
                cout<<cycle[i][j]<<" ";
            }cout<<"\n";
        }*/
        set<vector<int> > :: iterator it;
        //int count = 0;
        vector<vector<int> > ccc;
        for(it = cycle.begin(); it!=cycle.end(); it++){
            ccc.push_back(*it);
        }
        cout<<ccc[0].size()<<"\n";
        //r.push_back(ccc[0][0]);
            for(int j=0; j<ccc[0].size(); j++){
                cout<<ccc[0][j]<<" ";
            }cout<<"\n";
        for(int i=1; i<k; i++){
            cout<<ccc[i].size()<<"\n";
            for(int j=0; j<ccc[i].size(); j++){
                cout<<ccc[i][j]<<" ";
                
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

