#include <bits/stdc++.h>

using namespace std;

bool comparator(pair<int, int>& a, pair<int, int>& b) {
  if(a.first == b.first) {
    return a.second > b.second;
  }
  return a.first < b.first;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int T, n, k, m;
  vector<pair<int, int>> v;

  cin>>T;
  while (T--){
    /* code */
    cin>>n>>k;
    for(int i=0; i<n; i++) {
      cin>>m;
      pair<int, int> p = {m, 0};
      v.push_back(p);
    }

    for(int i=0; i<n; i++) {
      cin>>m;
      v[i].second = m;
    }

    // sort
    sort(v.begin(), v.end(), comparator);

    for(auto p: v) {
      if(k >= p.first) {
        k += p.second;
      } else {
        break;
      }
    }

    // after completion
    v.clear();

    cout<<k<<"\n";
  }
  
  return 0;
}