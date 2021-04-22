#include <bits/stdc++.h>
using namespace std;

int main() {
  int T, n, m, a;
  vector<int> odd;
  vector<int> even;
  vector<pair<int, int> > answer;

  cin>>T;
  while(T--) {
    cin>>n;
    m = n << 1;
    for(int i=1; i<=m; i++) {
      cin>>a;
      if( (a&1) == 1) { odd.push_back(i);  }
      else{ even.push_back(i);  }
    }

    for(int i=0; i+1<odd.size(); i+=2) {
      answer.push_back({odd[i], odd[i+1]});
    }

    for(int i=0; i+1<even.size(); i+=2) {
      answer.push_back({even[i], even[i+1]});
    }

    for(int i=0; i<n-1; i++) {
      cout<<answer[i].first<<" "<<answer[i].second<<"\n";
    }

    answer.clear();
    odd.clear();
    even.clear();
  }
}