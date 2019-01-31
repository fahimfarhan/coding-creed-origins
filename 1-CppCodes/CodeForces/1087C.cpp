#include <bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d",&x)
#define sf(x) scanf("%f",&x)

#define pi(x) printf("%d\n",x)
#define pf(x) printf("%.4f\n",x)

#define ll long long int

#define sll(x) scanf("%I64d",&x);
#define pll(x) printf("%-I64d\n",x);
bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


int n,m;
int **g;
bool *isvisited;

int xa,ya, xb,yb,xc,yc;


void floodfill(){
    double dis = INT_MAX;
    
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
  cin>>xa>>ya;
  cin>>xb>>yb;
  cin>>xc>>yc;
    g = new int*[1005];
    for(int i=0; i<1005; i++){
        g[i] = new int[1005];
    }
    
    for(int i=0; i<=1000; i++){
        for(int j=0; j<=1000; j++)
            g[i][j] = 0;
    }

    g[xa][ya] = -1;
    g[xb][yb] = -1;
    g[xc][yc] = -1;



  for(int i=0; i<1005; i++){    delete[] g[i];  }
  delete[] g;
  return 0;
}
