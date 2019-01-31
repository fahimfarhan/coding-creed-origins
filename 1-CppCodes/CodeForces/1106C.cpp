#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

#define ll long long int

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


int n,m, sj;
int *a;
ll s;
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

    cin>>n;
    a = new int[n+1];

    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    sort(a,a+n);
    s = 0;
    for(int i=0; i<n/2; i++){
        sj= a[i] + a[n-1-i];
        s = s+sj*sj;
    }
    cout<<s<<"\n";

    delete[] a;
  return 0;
}

