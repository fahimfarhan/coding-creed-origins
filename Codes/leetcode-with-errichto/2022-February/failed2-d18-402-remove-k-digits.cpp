#include <bits/stdc++.h>
using namespace std;

#define MIN_MONOTONIC -1
#define MAX_MONOTONIC 1


template <typename T>
class MonotonicStack{
private:
  stack<T> st;
  int type;

public:
  // static int minMonotonic = -1;
  // static int maxMonotonic = 1;

  MonotonicStack(int type = MIN_MONOTONIC) {
    this->type = type;
  }

  ~MonotonicStack() {
    while (!st.empty()){
      st.pop();
    }
    
  }

  bool push(T n) {
    if(st.empty()) {
      st.push(n);
      return true;
    } else if( (type == MAX_MONOTONIC) && (st.top() <= n) ) {  // question: < or <= o.O
      st.push(n);
      return true;
    } else if( (type == MIN_MONOTONIC) && (st.top() >= n) ) {
      st.push(n);
      return true;
    }
    return false;
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
      string ret = "";
      MonotonicStack<char> ms(MIN_MONOTONIC);
      int N = num.size();

      if(k >= N){
        return "0";
      }

      int targetSize = N - k; // after removing k digits
      int lastInsertedPosition = N;
      int end = -1;
      while ( (ret.size() < targetSize) && (lastInsertedPosition > 0) ) {

        end = lastInsertedPosition;
        for(int i=end - 1; i >= 0; i--) {
          bool ok = ms.push(num[i]);
          if(ok) { lastInsertedPosition = i; }
        }

        string temp = "";
        while(!ms.empty()) {
          temp = temp + ms.top(); // + temp;
          ms.pop();
        }
        ret = ret+temp;
        cerr<<" ------- "<<ret<<" --------\n";
      }
      // trim zeros
      N = ret.size();
      int m = -1;
      for(int i=0; i<N; i++) {
        if(ret[i] != '0') {
          m = i; break;
        }
      }
      if( m != -1 ) {
        ret = ret.substr(m);
      }

      cerr<<" ------- "<<ret<<" --------\n";
      
      return ret;
    }

    string removeKdigitsV1(string num, int k) {
      MonotonicStack<char> ms(MIN_MONOTONIC);

      int N = num.size();
      if(k >= N) {
        return "0";
      }      
      for(int i=N-1; i>=0; i--) {
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
        ret = ret + ms.top(); // + ret;
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