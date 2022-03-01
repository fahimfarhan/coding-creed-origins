#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
      vector<int> v(n+1, 0);
      for(int i=1; i<=n; i=i<<1) {
        v[i] = 1;
      } 

      int j = 0;     
      for(int i=1; i<=n; i++) {
        if(v[i] == 1) { j = 0; }
        
        v[i] = v[j] + 1;
        j++;

      }
      return v;
    }
};

int main() {
  Solution s;
  vector<int> v = s.countBits(10);
  for(auto i: v) {
    cout<<i<<" ";
  }cout<<"\n";
  return 0;
}