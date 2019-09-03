#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

#define ll long long int

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);
void dfs();
void dfsvisit(int u);


int n,m;
vector<int> *g;
bool *isvisited;

list<int> path;
queue<int> q;
void bfs(){
    int start = 1;
    for(int i=1; i<=n; i++){
        if(g[i].size() == 2){
            start = i;
            break;
        }
    }
    int start1, start2;

    start1 =g[start][0];
    
     
    isvisited[start] = true;
    q.push(start1);

    path.push_back(start);
    while(!q.empty()){
        int u = q.front();
        path.push_back(u);
        q.pop();
        isvisited[u] = true;

        int v = 0;
        for(int i=0; i<g[u].size(); i++){
            v = g[u][i];
            if(!isvisited[v]){  q.push(v);}
        }
    }

    if(n>2){
        start2 = g[start][1];
        q.push(start2);

        while(!q.empty()){
            int u = q.front();
            path.push_front(u);
            q.pop();
            isvisited[u] = true;

            int v = 0;
            for(int i=0; i<g[u].size(); i++){
                v = g[u][i];
                if(!isvisited[v]){  q.push(v);}
            }
        }
    }

}


int main(int argc, char const *argv[])
{
	/* code */
  /* Soln soln */
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
    m = n-1;
    g = new vector<int>[n+10];
    isvisited = new bool[n+10];
    for(int i=0; i<=n; i++){    isvisited[i] = false; }
    int a,b;
    for(int i=0; i<m; i++){
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    //dfs();
    bfs();
     for (auto it = path.begin(); it != path.end(); ++it) 
     {
         cout <<(*it) <<" ";
     }    

    cout<<"\n";

  if(!g)delete[] g;
  if(!isvisited)delete[] isvisited;
  return 0;
}


