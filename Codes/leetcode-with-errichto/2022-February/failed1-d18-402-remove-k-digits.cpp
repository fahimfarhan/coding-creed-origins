#include <bits/stdc++.h>
using namespace std;

template <typename T>
class MonotonicStack{
private:
  stack<T> st;

public:
  void push(T n) {
    if(st.empty()) {
      st.push(n);
    } else if(st.top() <= n) {  // question: < or <= o.O
      st.push(n);
    }
  }

  T top() {
    //if(!st.empty())
      return st.top();
    //return nullptr;
  }

  void pop() {
    if(!empty())
      st.pop();
  }

  bool empty() {
    return st.empty();
  }

  int size() {
    return st.size();
  }


};

class Solution {
public:
    string removeKdigits(string num, int k) {
      MonotonicStack<char> ms;

      int N = num.size();
      if(k >= N) {
        return "0";
      }      
      for(int i=0; i<N; i++) {
        ms.push(num[i]);
      }

      cerr<<"1: ms.size = "<<ms.size()<<"\n";

      int msSize = ms.size();
      int diff = N - msSize;  // 0 <= diff <= k
      string ret = "";
      while (!ms.empty() && (ms.size() > (k - diff)) ) {
        /* code */
        char ch = ms.top();
        cerr<<"1.1: ch = "<<ch<<"\n";
        ret = ms.top() + ret;
        ms.pop();
      }

      cerr<<"2: res = "<<ret<<"\n";

      // remove leading zeros
      int N1 = ret.size();
      int start = -1;
      for(int i=0; i<N1; i++) {
        if(ret[i] != '0') {
          start = i;
          break;
        }
      }
      cerr<<"3: start = "<<start<<", ret = "<<ret<<"\n";

      if(start == -1) {
        return "0";
      }
      cerr<<"4: "<<"ret = "<<ret<<"\n";
      ret = ret.substr(start);
      cerr<<"5: "<<"ret = "<<ret<<"\n";
      return ret;
    }
};

int main() {
  string a = "12345";
  string b = a.substr(2);
  // cout<<b<<" \n";
 
  Solution s;
  cout<<s.removeKdigits("1432219", 3)<<"\n";
  cout<<s.removeKdigits("10200", 1)<<"\n";

  cout<<s.removeKdigits("10", 2)<<"\n";
  return 0;
}