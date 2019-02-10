#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

#define ll long long int

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);



vector<int> *g;
bool *isvisited;

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

  
    int T, n, casenum, a[2], b[2], c[2], x[2], y[2], z[2], da, db, dc;
   
    ll ans=0;
    casenum=0;
    cin>>T;
    while(T--){
        casenum++;
        cin>>n;
         a[0] = -1000; b[0]=-1000; c[0]=-1000;
          a[01] = 1000; b[01]=1000; c[01]=1000;
        for(int i=0; i<n; i++){
            cin>>x[0]>>y[0]>>z[0]>>x[01]>>y[01]>>z[01];
          
            //x axis intersection 
            a[0] = max(a[0], x[0]);
            a[1] = min(a[1], x[1]);

            // y axis intersection 
            b[0] = max(b[0], y[0]);
            b[1] = min(b[1], y[1]);

            // z axis intersection 
            c[0] = max(c[0], z[0]);
            c[1] = min(c[1], z[1]);
        }
/*
        da = (a[1] - a[0]);
        db = (b[1] - b[0]);
        dc = (c[1] - c[0]);
*/    
     

        da = max(a[1] - a[0], 0);
        db = max(b[1] - b[0], 0);
        dc = max(c[1] - c[0], 0);

        ans = da*db*dc;
        cout<<"Case "<<casenum<<": "<<ans<<"\n";
        
    }

  
  return 0;
}

