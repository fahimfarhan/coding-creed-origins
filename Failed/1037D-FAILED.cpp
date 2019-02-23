#include <bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d",&x)
#define sf(x) scanf("%f",&x)

#define pi(x) printf("%d\n",x)
#define pf(x) printf("%.4f\n",x)

#define ll long long int

#define sll(x) scanf("%I64d",&x);
#define pll(x) printf("%-I64d\n",x);

vector<int> *g;
bool *isVisited;
queue< pair<int,int> > q;

int *a;
int *cf;

int depth;

vector<int> *level;
int *levelWiseCF;

void bfs(){
    depth = 0;
    pair<int, int> p(1,depth);
    q.push(p);
    while( !q.empty() ){
        pair<int, int> r = q.front();
        q.pop();
        int node = r.first; int d = r.second;
        depth = d;
        level[d].push_back(node);
        levelWiseCF[d]+=node;
        for(int i=0; i<g[node].size(); i++){
            pair<int, int> s(g[node][i], d+1);
        }
    }
}

void check(){
    bool b = true;
    int aStart, aEnd;
    aStart = 1; aEnd = 0;
    if(levelWiseCF[0]!=cf[0]){   b = false; }
    if(b){
                for(int i=01; i<=depth; i++){
                int l = level[i].size();
                aEnd = aStart+l;

                int sum = cf[aEnd] - cf[aStart];
                if(sum!=levelWiseCF[i]){    b = false; break;  }
                aStart = aEnd;
            }
    }

    if(b){  cout<<"Yes\n";  }
    else{   cout<<"No\n";   }

}

int main(int argc, char const *argv[])
{
	/* code */
  /* Soln soln */
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
    depth = 0;
	int n;
    cin>>n;
    g = new vector<int>[n+1];
    isVisited = new bool[n+1];
    level = new vector<int>[n+1];
    levelWiseCF = new int[n+1];



    a = new int[n];
    cf = new int[n];

    for(int i=0; i<=n; i++){    isVisited[i]=false; levelWiseCF[i] = 0;    }
    for(int i=01; i<n; i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    cin>>a[0];
    for(int i=01; i<n; i++){
        cin>>a[i];
        cf[i] = a[i] + cf[i-1];
    }

    bfs();
    check();

    if(!g)delete[] g;
    if(!isVisited)delete[] isVisited;
    if(!level)delete[] level;
    if(!a)delete[] a;
    if(!a)delete[] cf;
    if(!levelWiseCF)delete[] levelWiseCF;
	return 0;
}
