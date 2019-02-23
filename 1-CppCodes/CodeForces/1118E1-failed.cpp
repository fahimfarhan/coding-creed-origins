#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

#define ll long long int

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


ll n,k;
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

  cin>>n>>k;
  ll count=0;

  for(int i=1; i<=k; i++){
    for(int j=i+1; j<=k; j++){
      count+=2;
    }
  }
  if(count < n){
    cout<<"NO\n";
    exit(0);
  }else{
    cout<<"YES\n";
  }
  count=0;
  for(int i=1; i<k; i++){
    for(int j=i+1; j<=k; j++){
      cout<<i<<" "<<j<<"\n";   
      count++;
      if(count == n){ break; }
      cout<<j<<" "<<i<<"\n";
      count++;      
            if(count == n){ break; }
    }
  }
  return 0;
}

