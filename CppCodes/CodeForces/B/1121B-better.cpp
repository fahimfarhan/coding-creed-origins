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

    int n,*a, dp[200001], maximus;
    maximus = 0; 
    for(int i=0; i<200001; i++){    dp[i] = 0; }
    cin>>n;
    a = new int[n+1];
    for(int i=0; i<n; i++){     cin>>a[i];  }

    for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
        if(i!=j){   dp[a[i]+a[j]]++;    }

    for(int i=0; i<200001; i++){    maximus = max(dp[i], maximus);  }
    
    maximus = maximus>>1;
    cout<<maximus<<"\n";
    
    delete[] a;
  
  return 0;
}