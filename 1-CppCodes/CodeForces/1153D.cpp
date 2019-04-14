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
bool *operation;

int dfs_visit(int u){
    //isvisited[u]=true;
    int ret=0;
    if(operation[u]){ ret= -1;  }
    else{   ret = }
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
    g = new vector<int>[n+1];
    isvisited = new bool[n+1];
    operation = new bool[n+1];
    for(int i=0; i<=n; i++){    isvisited[i]=false; operation[i]=0; }

    for(int i=1; i<=n; i++){    cin>>operation[i];  }

    int parent;
    for(int i=2; i<=n; i++){
        cin>>parent;
        g[parent].push_back(i);
    }

    dfs_visit(1);


    if(!g)delete[] g;
    if(!isvisited)delete[] isvisited;
    if(!operation)delete[] operation;

    return 0;
}
