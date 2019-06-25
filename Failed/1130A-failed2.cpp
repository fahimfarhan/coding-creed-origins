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

    int n,a,d=0, neg_count=0, pos_count=0, ceiling;
    cin>>n;

    ceiling = ceil((1.0*n)/2);
    
    for(int i=0; i<n; i++){
        cin>>a;
        if(a > 0){   pos_count++;   }
        else if( a < 0){   neg_count++; }
    }

    if(pos_count >= ceiling){   d = 1; }
    else if(neg_count >= ceiling ){ d = -1; }
    else{   d = 0; }
    cout<<d<<"\n";
  
  return 0;
}


