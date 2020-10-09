#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

#define ll long long int

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


ll a,n,m;
vector<int> *g;
bool *isvisited;

int main(int argc, char const *argv[])
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
    // int a=0;
    cin>>n>>m;
    if(n==1){ a = 1; }
    else if(n-m > m-1 ){ a=m+1; } // m is closer to 1 
    else{   a=m-1;  }
    cout<<a<<"\n";
  
  return 0;
}

