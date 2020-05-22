#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

typedef long long int ll;
// #define ll long long int
// other popular ones=> int64_t, uint64_t => use for 10^18
ll MODULO = 1e9+7;

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


// int n,m;
vector<int> *g;
bool *isvisited;

int n,m,k,u,v, bp; 
bool *h;

void f(){
    for(int i=0; i<k; i++){
        cin>>u>>v;
        if(h[bp]==1){  break; }

        if(u==bp){ bp = v; }
        else if(v == bp){ bp = u; }
        
        if(h[bp]==1){  break; }
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

    
    bp = 1;

    cin>>n>>m>>k;
    h = new bool[n+1];
    for(int i=0; i<=n; i++){    h[i]=0; }
    int x;
    for(int i=0; i<m; i++){ cin>>x; h[x]=1;  }
    f();

    cout<<bp<<"\n";

    delete[] h;
    return 0;
}
