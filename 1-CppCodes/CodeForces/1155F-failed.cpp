#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

#define ll long long int

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


int n,m,k;
vector<pair<int,int> > e;
int *d;

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
    for(int i=0; i<=n; i++){    d[i]=0; }

    int u,v,temp;
    for(int i=0; i<m; i++){
        cin>>u>>v;
        d[u]++; d[v]++;
        // if(u>v){ temp = u; u=v; v=u;   }
        e.push_back({u,v});
    }

    for(int i=0; i<m; i++){
        u = e[i].first; v = e[i].second;
        if( (d[u]>2) && (d[v]>2) ){
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
    return 0;
}
