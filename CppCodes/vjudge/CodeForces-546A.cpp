#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

#define ll long long int

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


// int n,m;
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
    
    ll k,w,n, sum, d;
    cin>>k>>n>>w;
    
    sum = w*(w+1)*k;
    sum=sum>>1; 
    
    d = sum-n;
    if(d<0){    d=0;    }
    cout<<d<<"\n";
  return 0;
}


