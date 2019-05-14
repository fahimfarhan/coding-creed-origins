#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

#define ll long long int
// other popular ones=> int64_t, uint64_t => use for 10^18
ll MODULO = 1e9+7;

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


int n,m;

int s1,t1,l1,s2,t2,l2;
bool flag;

vector<int> *g;
map< pair<int,int> , bool> mp;
bool *isvisited;
vector<int> path, pathFound;

void dfs_visit(int s,int t, int k){
    path.push_back(s);
    if( (k==0) && (s==t) ){ 
        for(int i=0; i<path.size(); i++){
            pathFound.push_back(path[i]);
        }
        flag = true;
        return; 
    }
    cerr<<"here1\n";
    if( k==0  ){ path.pop_back(); return; }
    cerr<<"here2\n";
    isvisited[s] = true;
    int v = 0, k1 = k-1;
    
    for(int i=0; i<g[s].size(); i++){
        v = g[s][i];
        if(!isvisited[v]){
            dfs_visit(v,t,k1);
        }
    }
    cerr<<"here3\n";
    path.pop_back();
    cerr<<"here4\n";
    return;
}

void dfs(){
    int a,b;

    flag =  false;
    for(int i=0; i<=n; i++){    isvisited[i]=0; }
    dfs_visit(s1,t1,l1);
    cerr<<"ok\n";
    for(int i=0; i<pathFound.size()-1; i++){
        a = pathFound[i]; b = pathFound[i+1];
        if(a>b){    swap(a,b);  }
        mp[{a,b}] = true;
    }
    cerr<<"ok1\n";
    while(!path.empty()){   path.pop_back();    }
    while(!pathFound.empty()){  pathFound.pop_back();   }

cerr<<"ok2\n";
    
    flag =  false;
    for(int i=0; i<=n; i++){    isvisited[i]=0; }
    dfs_visit(s2,t2,l2);
    cout<<"ok3\n";
    
    for(int i=0; i<pathFound.size()-1; i++){
        a = pathFound[i]; b = pathFound[i+1];
        if(a>b){    swap(a,b);  }
        mp[{a,b}] = true;
    }
    cerr<<"ok4\n";
    
    //while(!path.empty()){   path.pop_back();    }
    //while(!pathFound.empty()){  pathFound.pop_back();   }

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
    
    cin>>n>>m;
    cerr<<"ok 1.\n";
    g = new vector<int>[n+1];
    isvisited = new bool[n+1];
    cerr<<"ok 1.1\n";
    int u,v;
    for(int i=0; i<m; i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
        if(u>v){    swap(u,v);  }
        mp[{u,v}] = false;
    }
    cerr<<"ok 1.2\n";
    cin>>s1>>t1>>l1;
    cin>>s2>>t2>>l2;
    cerr<<"ok 1.3\n";
    dfs();
    cerr<<"ok 1.4\n";
    if(flag){
        int ans = 0;
        map< pair<int,int> , bool> :: iterator it;
        for(it = mp.begin(); it!= mp.end(); it++){
            if( (it->second) == true ){
                ans++;
            }
        }
        cout<<(m-ans)<<"\n";
    }else{
        cout<<"-1\n";   
    }


    if(!g)delete[] g;
    if(!isvisited)delete[] isvisited;

    return 0;
}
