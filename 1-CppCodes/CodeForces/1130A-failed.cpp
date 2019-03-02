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

    int n, ceiling, d; int *a;
    cin>>n;
    ceiling = ceil( (n*1.0)/2);

    a = new int[n+1];

    for(int i=0; i<n; i++){
        cin>>a[i]; 
    }

    sort(a,a+n);
    int lb = lower_bound(a,a+n,0)-a;
    lb = lb+1;
    int ub = upper_bound(a,a+n,0)-a;
    ub++;

    int ub_num = n-ub+1;
    // cout<<lb<<"\n";
    if(lb < ceiling && ub_num >=ceiling){
        d = 1;
    }else if(ub_num < ceiling && lb >= ceiling ){
        d = -1;
    }else{
        d = 0;
    }
    cout<<d<<"\n";
    delete[] a;
  
  return 0;
}


