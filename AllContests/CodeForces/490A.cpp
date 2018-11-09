#include <bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d",&x)
#define sf(x) scanf("%f",&x)

#define pi(x) printf("%d\n",x)
#define pf(x) printf("%.4f\n",x)

#define ll long long int

#define sll(x) scanf("%I64d",&x);
#define pll(x) printf("%-I64d\n",x);

vector<int> v[4];
int main(int argc, char const *argv[])
{
	/* code */
  /* Soln soln */
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

	int n;
    cin>>n; 
    for(int i=01; i<=n; i++){
        int t;
        cin>>t;
        v[t].push_back(i);
    }

    int minimus = INT_MAX;
    for(int i=1; i<=3; i++){
        // minimus = min(minimus, v[i].size());
        if(v[i].size()<minimus){ minimus = v[i].size();  }
    }
    cout<<minimus<<"\n";
    for(int i=0; i<minimus; i++){
        for(int j=1; j<4; j++){
            int a = v[j][v[j].size()-1];
            cout<<a<<" ";
            v[j].pop_back();
        }
        cout<<"\n";
    }

	return 0;
}
