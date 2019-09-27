/* Author : Qazi Fahim Farhan (@fahimfarhan) */
/* May the CodeForces be with you! */

#include <bits/stdc++.h>

using namespace std;

#define PI 2*acos(0)

//typedef long long int ll;
 #define ll long long int
// other popular ones=> int64_t, uint64_t => use for 10^18
ll MODULO = 1e9+7;

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


// int n,m;s
bool *isvisited;

vector<pair<int,int> > *g;
queue<pair<int,int> > q;
int *v;
int *res;

int n,k,d;

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

    cin>>n>>k>>d;
    g = new vector<pair<int,int> >[n+1];
    v = new int[n+1]; res = new int[n+1];

    for(int i=0; i<=n; i++){ v[i] = 0; res[i] = 0; }

    int policeStationPos;
    for(int i=0; i<k; i++){
        cin>>policeStationPos;
        q.push({policeStationPos,0});
    }

    

    for(int i=1; i<=n-1; i++){
        int u1,v1;
        cin>>u1>>v1;
        g[u1].push_back({v1,i});
        g[v1].push_back({u1,i});
    }

    while(!q.empty()){
        int pos = q.front().first;
        int from = q.front().second;

        q.pop();
        if(v[pos]){ continue;   }
        v[pos] = 1;
        for(int i=0; i<g[pos].size(); i++){
            if(g[pos][i].first != from){
                int nextCity = g[pos][i].first;
                int edgeNum = g[pos][i].second;
                if(v[nextCity]){  res[edgeNum] = 1;  }
                else{   q.push({nextCity, pos}); }
            }
        }
    }

    int rescount = 0;

    for(int i=1; i<=n-1; i++){  if(res[i])  rescount++; }

    cout<<rescount<<"\n";
    for(int i=1; i<=n-1; i++){  if(res[i])  cout<<i<<" "; }
    cout<<"\n";

    return 0;
}

/**
Dread it, run from it, destiny arrives all the same !
I find your lack of faith in the CodeForces disturbing! >_<
Love you 3000 !
Keep It Simple Stupid (KISS)!
Good Hunting 47!
*/
/**
AC I - Redemption AC II - Revenge AC: Brotherhood - Justice AC: Revelation - Answers 
AC III - Freedom AC IV - Glory AC Rogue - Betrayal AC Unity - Love AC Syndicate - Family 
AC Origins - Beginnings 
*/
