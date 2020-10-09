#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

#define ll long long int

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);



vector<int> *g;
bool *isvisited;

ll f(ll b,ll p, ll m){
  if(p == 1){ return b%m; }
  if(p==0){ return 1%m; }
  ll ret=0;

  if(p&1 == 1){
    // odd number
    ll p1 = p>>1; // p=p/2
    ll temp = f(b,p1,m );
    temp = temp%m;
    ret = temp*temp*f(b,1,m);
    
  }else{

    ll p1 = p>>1; // p=p/2
    ll temp = f(b,p1,m );
    temp = temp%m;
    ret = temp*temp;
  }


  ret = ret%m;
  return ret;
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

  ll R,B,P,M;
  while(cin>>B>>P>>M)
  {
    //cin>>B>>P>>M;
    
    R=f(B,P,M);
    /*
    for(int i=1; i<=P; i++){
      R = ((R%M)*(i%M))%M;
    }*/
    cout<<R<<"\n";
    cout<<flush;
  }
  
  return 0;
}


