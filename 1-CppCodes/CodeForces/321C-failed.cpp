#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

#define ll long long int

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


int n,m;
vector<int> *g;
bool *isvisited;
int  *myrank;

bool isPossible;
int maximus;

void dfs_visit(int u, int r){
    if(r>51){
        isPossible = false; 
        cout<<"Impossible!\n";
        exit(0); 
    }
    maximus = max(maximus, r);
    myrank[u] = r;
    isvisited[u] = true;
    int v = 0;
    int nextr = r+1; 
    for(int i=0; i<g[u].size(); i++){
        v = g[u][i];
        if(!isvisited[v]){
            dfs_visit(v, nextr);
        }
    }

}

void dfs(){
    maximus = 0;
    for(int i=0; i<=n; i++){    isvisited[i]=false; }
    isPossible = true;
    for(int i=1; i<=n; i++){

        if(!isvisited[i]){
            dfs_visit(i, 1);
        }
    }
}

void setRank(){
    if(maximus<=26){
        for(int i=1; i<=n; i++){
            myrank[i] = 'A'+myrank[i]-1;
        }
    }else{
         for(int i=1; i<=n; i++){
             if(myrank[i]<=26){
                 myrank[i] = 'Z'-myrank[i]+1;
             }else{
                 myrank[i] = 'A'+ myrank[i] - 26;
             }
            
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

    cin>>n;
    m=n-1;
    g = new vector<int>[n+1];
    isvisited=new bool[n+1];
    myrank = new int[n+1];


    int a,b;
    for(int i=0; i<m; i++){
        cin>>a>>b;
        g[a].push_back(b); g[b].push_back(a);
    }

    dfs();
    setRank();
    for(int i=1; i<=n; i++){    cout<<((char)myrank[i])<<" ";     }cout<<"\n";

    if(!myrank)delete[] myrank;
    if(!isvisited)delete[] isvisited;
    if(!g)delete[] g;
    
    return 0;
}
