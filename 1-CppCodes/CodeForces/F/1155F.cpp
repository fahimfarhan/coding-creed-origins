#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

#define ll long long int

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


int n,m,k;
vector<pair<int,int> > e;
bool *isVisitedEdge;
int *d;

vector<int> *g;
bool *isvisited;

void dfs_visit(int u){
    isvisited[u] = true;
    int v = 0, a,b, temp;
    for(int i=0; i<g[u].size(); i++){
        v = g[u][i];
        if(!isvisited[v]){
            a = min(u,v); b = max(u,v);
            //if(a>b){  temp = a; a=b; b=temp;  }
            for(int j=0; j<m; j++){
                if( (e[j].first==a) && (e[j].second==b) ){  isVisitedEdge[j]=true; break; }
            }
            dfs_visit(v);
        }
    }
}

void dfs(){
    for(int i=1; i<=n; i++){
        if(!isvisited[i]){
            dfs_visit(i);
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

    cin>>n>>m;
    d = new int[n+1];
    isVisitedEdge = new bool[m+1];
    g = new vector<int>[n+1];
    isvisited = new bool[n+1];

    for(int i=0; i<=n; i++){    d[i]=0; isvisited[i] = false; }
    for(int i=0; i<=m; i++){    isVisitedEdge[i] = false;  }

    int u,v,a,b;
    for(int i=0; i<m; i++){
        cin>>u>>v;
        d[u]++; d[v]++;
        a = min(u,v); b = max(u,v);
        e.push_back({a,b});
    }

    dfs();

    for(int i=0; i<m; i++){
        u = e[i].first; v = e[i].second;
        if( (d[u]>2) && (d[v]>2) && (isVisitedEdge[i]==false) ){
            e[i].first = -1; e[i].second = -1; 
            d[u]--; d[v]--;
        }else{
            k++;
        }
    }



    cout<<k<<"\n";
    for(int i=0; i<m; i++){
        if(e[i].first!=-1){
            u=e[i].first; v=e[i].second;
            cout<<u<<" "<<v<<"\n";
        }
    }


    delete[] d; 
    delete[] isVisitedEdge;
    return 0;
}
