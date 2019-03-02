#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

#define ll long long int

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


//int n,m;
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

    int a,d=0,ceiling=0,n,pos=0,neg=0;
    cin>>n;
    ceiling = (n+1)/2;
    for(int i=0; i<n; i++){
        cin>>a;
        if(a>0){    pos++; }
        else if(a<0){   neg++;}
    }

    if(pos >=ceiling){  d=1;}
    else if(neg >=ceiling){ d=-1; }
    else{   d=0; }

    cout<<d<<"\n";
  
  return 0;
}


