#include <bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d",&x)
#define sf(x) scanf("%f",&x)

#define pi(x) printf("%d\n",x)
#define pf(x) printf("%.4f\n",x)

#define ll long long int

#define sll(x) scanf("%I64d",&x);
#define pll(x) printf("%-I64d\n",x);

#define INF 1000
int n,m;
vector<int> *g;
bool *isvisited;


int **dis;
int *weight;
map<int, pair<int, int> > E;

void FloydWarshallAlgo(){
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(dis[i][j] > dis[i][k]+dis[k][j]){
                    dis[i][j]=dis[i][k]+dis[k][j];
                }
            }
        }
    }
}

void printer(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout<<dis[i][j]<<" ";
        }cout<<"\n";
    }
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

  cin>>n>>m;

    dis = new int*[n+1];
    for(int i=0; i<=n; i++){    dis[i] = new int[n+1];  }

    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){    dis[i][j] = INF;    }
    }
    for(int i=0; i<=n; i++){    dis[i][i] = 0; }

    int a,b,c;
    for(int i=0; i<m; i++){
        cin>>a>>b>>c;
        dis[a][b] = c;
        //E[i] = {a,b};
    }
printer();
cout<<"-----------------\n";
    FloydWarshallAlgo();
    printer();

    for(int i=0; i<=n; i++){if(!dis[i])delete[] dis[i];   }
    if(!dis)delete[] dis;
	return 0;
}
