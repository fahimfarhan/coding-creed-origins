// graph 21, ds 21
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
bool ans;

int numOfV, numOfE;

bool dfs_visit(int u){
    isvisited[u]=true;
    bool ret=true;
    int v;
    numOfV++;
    numOfE+=g[u].size();
    int degreeOfU=g[u].size();
    int degreeOfV=0;
    for(int i=0; i<degreeOfU; i++){
        v = g[u][i];
        if(!isvisited[v]){
            degreeOfV = g[v].size();
            if(degreeOfU != degreeOfV){ return false;   }
            else{  
                ret = dfs_visit(v);
                if(ret==false){ return ret; }
           }
        }
    }

    return ret;
}


void dfs(){
    ans = true;
    
    for(int i=1; i<=n; i++){
        if(!isvisited[i]){
            //depth=0;
            numOfE=0; numOfV=0;
            ans = dfs_visit(i);
            if(ans==false){ break;}
            else if( numOfE != (numOfV*(numOfV-1)) ){
                ans=false; break;
            }
           
        }
    }

    if(ans){    cout<<"YES\n";   }
    else{       cout<<"NO\n" ;   }
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

    for(int i=0; i<=n; i++){    isvisited[i] = false;   }

    int a,b;
    for(int i=0; i<m; i++){
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs();

    delete[] g;
    delete[] isvisited;
    return 0;
}
