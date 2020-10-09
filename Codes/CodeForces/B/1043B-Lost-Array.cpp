#include <bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d",&x)
#define sf(x) scanf("%f",&x)

#define pi(x) printf("%d\n",x)
#define pf(x) printf("%.4f\n",x)

#define ll long long int

#define sll(x) scanf("%I64d",&x);
#define pll(x) printf("%-I64d\n",x);

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
    set<int> s;
    int prev = 0; int a = 0;
    int x_imodn = 0;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a;
        x_imodn = a -prev;
        // if(x_imodn<0){ x_imodn+=n;}
         prev = a;
         s.insert(x_imodn);
    }

    int l = s.size();
    cout<<l<<"\n";
    set<int>::iterator it;
    vector<int> v;
    for(it=s.begin(); it!=s.end(); it++){
        //cout<<*it<<" ";
        int y = *it;
        // if(y < 0 ){ y += l; }
        v.push_back(y);
    }

    sort(v.begin(), v.end());
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<"\n";
	return 0;
}
