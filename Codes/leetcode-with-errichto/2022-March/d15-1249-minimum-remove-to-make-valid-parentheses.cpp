#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
      stack<pair<int, char>> st;

      int N = s.size();
      char ch = 0;
      for(int i=0; i<N; i++) {
        ch = s[i];
        if(ch == '(' || ch == ')') {  
          pair<int, char> p = {i, ch};

          if(st.empty()) {
            st.push(p);
          } else if(st.top().second == '(' && p.second == ')'){
            st.pop();
          } else {
            st.push(p);
          }
        }
      }

      while (!st.empty()){
        /* code */
        auto p = st.top();
        st.pop();

        s[p.first] = '|';
      }

      string t = "";
      for(int i=0; i<N; i++) {
        if(s[i] != '|') {
          t += s[i];
        }
      }
      
      return t;      
    }
};


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  cout<<"Hello there from vim!\n";
  return 0;
}
// 1249-minimum-remove-to-make-valid-parentheses
