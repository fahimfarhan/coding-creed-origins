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

    int n;
    ll ans;
    ll *A, *B;

    cin>>n;
    A = new ll[n];
    B = new ll[n];

    for(int i=0; i<n; i++){
        cin>>A[i];
    }
        for(int i=0; i<n; i++){
        cin>>B[i];
    }

    sort(A,A+n); sort(B,B+n);
    ans = 0;
    for(int i=0; i<n; i++){
        ans+=abs(A[i] - B[i]);
        ans = ans%1000000007;
    }
    cout<<ans<<"\n";
    delete[] A;
    delete[] B;
  
  return 0;
}

