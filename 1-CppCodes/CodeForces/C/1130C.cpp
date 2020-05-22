#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

#define ll long long int

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


int n,m, sr,sc,tr,tc;
int **g;
string str;
bool *isvisited;

bool isValidIndex(int i,int j){
  if(i>=1 && i<=n && j>=1 && j<=n){ return true; }
  return false;
}

void bfs(){
  queue<pair<int, int> > q;
  q.push({sr,sc});

  int row_dir[4] = {1,-1,0,0};
  int col_dir[4] = { 0,0,1,-1};

  int next_r, next_c;
  pair<int,int> p;
  while(!q.empty()){
    p = q.front();
    // p.first = q.front().first; p.second = q.front().second ;
    q.pop();

    for(int i=0; i<4; i++){
      next_r = p.first+row_dir[i]; next_c = p.second + col_dir[i];
      if(isValidIndex(next_r, next_c)){
        
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
  g = new int*[n+1];
  for(int i=0; i<=n; i++){  g[i] = new int[n+1];  }

  cin>>sr>>sc;
  cin>>tr>>tc;

  for(int i=01; i<=n; i++){
    cin>>str;
    for(int j=0; j<n; j++){
      if(str[j]=='0'){g[i][j+1]=0;}
      else{ g[i][j+1] = 1; }
    }
  }

  bfs();

  for(int i=0; i<=n; i++){  delete[] g[i];  }
  delete[] g;
  return 0;
}


