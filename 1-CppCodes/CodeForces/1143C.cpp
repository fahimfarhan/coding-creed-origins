#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

#define ll long long int

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);
void dfsvisit(int u);
void dfs();

int n,m;
vector< int > *g;

vector<int> order;
bool *isvisited, *c;
//int *p;
bool flag;
void dfs(){
    for(int i=1; i<=n; i++){
        if(!isvisited[i]){
            dfsvisit(i);
        }
    }
}

void dfsvisit(int u){
    isvisited[u] = true;
    int v, c1=c[u];
    bool allBadChildren=true;
    for(int i=0; i<g[u].size(); i++){
        v = g[u][i];
        allBadChildren = allBadChildren&c[v];
    }

    if( (c1 == 1) && (allBadChildren== true) ){
        order.push_back(u);//cout<<u<<" "; 
        //flag = true;
    }

    for(int i=0; i<g[u].size(); i++){
        v = g[u][i];
        if(!isvisited[v]){  dfsvisit(v);    }
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
    flag=false;
    cin>>n;
    g = new vector< int >[n+1];
    isvisited = new bool[n+1];
    //p = new int[n+1];
    c = new bool[n+1];
    for(int i=0; i<=n; i++){    isvisited[i] = false;   }
    int p1,c1;
    for(int i=1; i<=n; i++){
        cin>>p1>>c1;
        if(p1==-1){  p1=0; }
        g[p1].push_back(i);
        c[i] = c1;
    }
    dfs();
    if(order.size()==0){  cout<<"-1"; }
    else{
        sort(order.begin(), order.end());
        for(int i=0; i<order.size(); i++){  cout<<order[i]<<" ";  }
    }
    cout<<"\n";
    if(!g)delete[] g;
    if(!isvisited)delete[] isvisited;
    if(!c)delete[] c;
    return 0;
}