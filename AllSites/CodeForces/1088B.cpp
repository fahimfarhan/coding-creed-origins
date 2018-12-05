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

	int n, k;
    ll a;
    priority_queue<ll> pq;
    vector<ll> v;
    cin>>n>>k;
    for(int i=0; i<n; i++){
        cin>>a;
        pq.push(-a);
    }

    ll toMinus = 0; 
    for(int i=0; i<k; i++){
        if(pq.size() == 0){
            break; //cout<<"0"<<"\n";
        }else{
            ll b,c;
            while(true){
 b = pq.top();
            b = -b;
            c = b - toMinus;
                    if(c<=0){ pq.pop(); }
            else break; 
            }
                    //else
                    {
                        v.push_back(c);
                        //cout<<c<<"\n";
                        toMinus+=b;
                    }
        }
        
    }

    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<"\n";
    }
    for(int i=0; i<k-v.size(); i++){
        cout<<"0\n";
    }
	return 0;
}
