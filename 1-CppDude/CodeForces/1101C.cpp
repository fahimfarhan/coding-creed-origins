
#include <bits/stdc++.h>

using namespace std;

int
main ()
{
    ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T,n, l,r, val, mx;
  cin>>T;
  while(T--){
      cin>>n;
      vector< pair<int, int> > seg, seg2;
      for(int i=0; i<n; i++){
          cin>>l>>r;
          seg.push_back({l,r});
          seg2.push_back({l,r});
      }
      
      sort(seg.begin(), seg.end());
      val=-1;
      mx = 0;
      for(int i=0; i<n-1; i++){
          if(seg[i].second < seg[i+1].first && seg[i+1].first>mx){
              val = seg[i+1].first;
          }
          mx = max(mx,seg[i].second);
          
      }
      if(val==-1){  cout<<"-1 ";   }
      else{
          for(int i=0; i<n; i++){
              if(seg2[i].second < val){ cout<<"1 ";    }
              else{ cout<<"2 ";    }
          }
      }
      cout<<"\n";
  }

  return 0;
}