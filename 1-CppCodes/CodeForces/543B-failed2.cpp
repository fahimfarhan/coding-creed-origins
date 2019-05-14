#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

#define ll long long int
// other popular ones=> int64_t, uint64_t => use for 10^18
ll MODULO = 1e9+7;

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


int n,m, s1,t1,s2,t2,l1,l2;
vector<int> *g;
bool *isvisited;
int *parent;
map< pair<int,int>, bool> E;

bool flag;

void kbfs(int s, int t, int k){
    for(int i=0; i<=n; i++){    isvisited[i]=false; parent[i]=0;     }
    queue<pair<int,int> > q;
    q.push({s,k});

    while(!q.empty()){
        pair<int,int> p = q.front();
        q.pop();

        int u = p.first, d = p.second-1;
        //cout<<u<<" "<<d<<"\n";
        isvisited[u] = true;  

        if(d<0){    break;   }
        
        else if(u==t){    break;    }
        else{
            int v=0;
            for(int i=0; i<g[u].size(); i++){
                v = g[u][i];
                if(!isvisited[v]){
                    q.push({v,d});
                    parent[v] = u;
                }
            }
        }
    }
    //cout<<parent[t]<<" parent t\n";
    if(parent[t]==0){   flag = false; return;   }
    else{
        int i = t, j=0, a,b;
        while(parent[i]!=s){
            j = parent[i];
            a=i, b = j;
            if(a>b){    swap(a,b);  }
            E[{a,b}]=true;

            i=j;
        }
        a = i; b = s;
        if(a>b){    swap(a,b);  }
        E[{a,b}]=true;
        return;
    }
}

void bfs(){
    flag = true;
    kbfs(s1,t1,l1);
    kbfs(s2,t2,l2);

    kbfs(t1,s1,l1);
    kbfs(t2,s2,l2);

    
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
    g = new vector<int>[n+1];
    isvisited = new bool[n+1];
    parent = new int[n+1];

    int a,b;
    for(int i=0; i<m; i++){
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);

        if(a>b){    swap(a,b);  }
        E[{a,b}] = false; 
    }
    cin>>s1>>t1>>l1;
    cin>>s2>>t2>>l2;

    flag = true;
    bfs();
    if(flag == false){  
        cout<<"-1\n";
    }else{
        int ans = 0;
        map< pair<int,int> , bool> :: iterator it;
        for(it = E.begin(); it!= E.end(); it++){
            if( (it->second) == true ){
                ans++;
            }
        }
        cout<<(m-ans)<<"\n";

    }

    delete[] isvisited;
    delete[] g;
    delete[] parent;

    return 0;
}
