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

	int n, score, maximus, *a;
    string name, ans;
    map<string, int > mp;
    
    maximus = INT_MIN;
    ans = "";
    cin>>n;
    a = new int[n];
    for(int i=0; i<n; i++){
        cin>>name>>score;
        if(mp.count(name)){
            mp[name]+=score;
            // if(mp[name]<0){ mp[name] = 0; }
        }else{  mp[name] = score; }

        //if(mp[name]>maximus){   maximus = mp[name]; ans = name; }
    }

    map<string, int>:: iterator it;
    for(it = mp.begin(); it!=mp.end(); it++){
        //if(it->second>maximus){ maximus = it->second;}
        maximus = max(maximus, it->second);
    }

   

    cout<<ans<<"\n";
	return 0;
}
