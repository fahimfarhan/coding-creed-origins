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

	int n, maximus;
    map<string, vector<int> > mp;
    vector<int> candidates;
    
    int score; 
    string name;

    cin>>n;
    maximus = INT_MIN;
    for(int i=0; i<n; i++){
        cin>>name>>score;
        int temp = 0;
        if(mp[name].size()==0){
            mp[name].push_back(score);
            temp = score;
        }else{
            temp = mp[name][mp[name].size()-1] + score;
            mp[name].push_back(temp);
        }
        if(temp>maximus){  maximus = temp; }
    }

    map<string, vector<int> >::iterator it;
    
    string ans = "";
    int index_max = INT_MAX;
    for(it = mp.begin(); it!=mp.end(); it++){
        vector<int> v = it->second;
        int l = v.size() - 1;
        if(v[l]==maximus){ 
            if(l<index_max){
                ans = "";
                index_max = l;
                ans = it->first;
            }
        }
        
    }

    cout<<ans<<"\n";
	return 0;
}
