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
int *a;

int main(int argc, char const *argv[])
{
	/* code */
  /* Soln soln */
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

    cin>>T;
    while(T--){
        cin>>N;
        
        vector<pair< int,int> > v;
        
        a = new int[N+1];
        for(int i=0; i<N; i++){
            cin>>a[i];
        }
        bool b = true;
        int j=0;
        int l,u;
        l = a[0];
        while(j<N){
            if(a[j]<a[j-1]){
                u = a[j-1];
                if(l!=u){
                    int small = min(l,u);
                    int big = max(l,u);
                    pair<int,int> p; p.first=small; p.second = big;
                    v.push_back(p);
                }
                
                l = a[j];
                j++;
            }
        }
        int count = 0;
        for(int i=0; i<v.size(); i++){
            for(int j=0; j<v.size(); j++){
                if(i=!j){
                    if( ( (v[i].first < v[j].first) && (v[j].second < v[i].second) ) || 
                    ( (v[j].first < v[i].first) && (v[i].second < v[j].second) )
                     ){
                         count++;
                    }
                }
                if(count>1){    b = false; break;}
            }
        }

        if(b){  cout<<"YES\n"; }
        else{   cout<<"NO\n";   }

        if(!a)delete[] a; 
    }
	return 0;
}
