#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    string removeDuplicateLetters(string s) {
      string result = "";

      int kount[26] = {0};
      bool isVisited[26] = {false};

      stack<char> st;

      int N = s.size();
      for(int i=0; i<N; i++){
        int j = s[i] - 'a';
        kount[j]++;
      }

      for(int i=N-1; i>=0; i--) {
        int j = s[i] - 'a';
        char ch = s[i];

        /*
        if(st.empty() 
            || ( (!st.empty()) && (ch > st.top()) ) 
          ) {
          st.push(ch);

          isVisited[j] = true;
          kount[j]--;
        } else {
          char top = st.top();
          int k = top - 'a';

          if(kount[k] > 0) {
            st.pop();
            isVisited[k] = false;

            st.push(ch);
            isVisited[j] = true;
            kount[j]--;
          }
        }*/

        if( (!st.empty()) && (ch <= st.top())  ) {
          char top = st.top();
          int k = top - 'a';
          if(kount[k] > 0) {
            st.pop();
            isVisited[k] = false;
          }

          st.push(ch);

          isVisited[j] = true;
          kount[j]--;
        }
      }

      while(!st.empty()) {
        char top = st.top();
        result = result + st.top();
      }

      return result;
    }
};

int main() {
  return 0;
}
