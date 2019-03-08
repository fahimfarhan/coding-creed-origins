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

    int n,m,len;
    int *a, *b;
    cin>>n;
    
    len = n<<1;
    
    a = new int[len+1];
    b = new int[len+1];

    for(int i=0; i<len; i++){   
        cin>>m;    
        if(a[m]!=0){    b[m]=i; }
        else{   a[m] = i;   } 
    }

    ll ans = 0;
    for(int i=0; i<n; i++){
        //ans+=();
    }


    if(!a)delete[] a;
    if(!b)delete[] b;
  return 0;
}


