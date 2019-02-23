#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

#define ll long long int

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


int n,m;
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

int64_t w1,h1,w2,h2,a,b,c,d,e,f, ans=0;

cin>>w1>>h1>>w2>>h2;

a = w2; b = w1; 
c = h1+h2+2;
d = h1+1;
e = h2; 
if(w1-w2 == 0){ f = 1;}
else{   f = w1-w2+1; }
ans = a+b+c+d+e+f;
  cout<<ans<<"\n";
  return 0;
}


