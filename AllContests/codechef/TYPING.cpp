#include <bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d",&x)
#define sf(x) scanf("%f",&x)

#define pi(x) printf("%d\n",x)
#define pf(x) printf("%.4f\n",x)

#define ll long long int

#define sll(x) scanf("%I64d",&x);
#define pll(x) printf("%-I64d\n",x);


int T,N;
map<string, bool> mp;
map<char, char> h;

// d,f --> left
// j,k --> right
int main(int argc, char const *argv[])
{
	/* code */
  /* Soln soln */
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);

    h['d'] = 'l';
    h['f'] = 'l';

    h['j'] = 'r';
    h['k'] = 'r';

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

    cin>>T;
    while(T--){
        cin>>N;
        double count = 0;
        double ans = 0;

        for(int i=0; i<N; i++){
            string s;
            cin>>s;
            int d = 1;
            count = 0;


            if(mp.count(s)){  d = 2; }
            // cout<<"d="<<d<<"\n";
            count+=.2;
            char prev_hand = h[s[0]];
            for(int j=1; j<s.size(); j++){
                if(prev_hand == h[s[j]]){   count+=.4; }
                else{   count+=.2; }
                prev_hand = h[s[j]];
            }
            count/=d;

            mp[s] = true;
            ans+=count;
        }
        cout<<ans*10<<"\n";


    }
	return 0;
}
