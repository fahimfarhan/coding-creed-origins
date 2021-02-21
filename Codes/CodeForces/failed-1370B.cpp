#include <bits/stdc++.h>
 
#define ll int
 
using namespace std;

inline int getRectifiedIndex(const int& deleteIndex1, const int& deleteIndex2, const int& n) {
  if(n < deleteIndex1) {  return n; }
  else if(n > deleteIndex2) { return (n - 2); }
  else{ return (n-1); }
}
 
int main() {
  ll T, n, a, b;
  stack<ll> oddNumbers, evenNumbers;
  cin>>T;
  while (T--){
    /* code */
    cin>>n;
    n = n << 1;
    for(int i=1; i<=n; i++) {
      cin>>a;
      if( (a & 1) == 1) { oddNumbers.push(i); }
      else{ evenNumbers.push(i); }
    }

    int deleteIndex1, deleteIndex2;
    if( (oddNumbers.size() & 1) == 1) {
      deleteIndex1 = oddNumbers.top(); oddNumbers.pop();
      deleteIndex2 = evenNumbers.top(); evenNumbers.pop();
    }else{
      deleteIndex1 = oddNumbers.top(); oddNumbers.pop();
      deleteIndex2 = oddNumbers.top(); oddNumbers.pop();
    }

    if(deleteIndex1 > deleteIndex2) {
      swap(deleteIndex1, deleteIndex2);
    }
 
    while(!oddNumbers.empty()) {
      a = oddNumbers.top(); oddNumbers.pop();
      b = oddNumbers.top(); oddNumbers.pop();
      
      a = getRectifiedIndex(deleteIndex1, deleteIndex2, a);
      b = getRectifiedIndex(deleteIndex1, deleteIndex2, b);
      cout<<a<<" "<<b<<"\n";
    }
 
    while(!evenNumbers.empty()) {
      a = evenNumbers.top(); evenNumbers.pop();
      b = evenNumbers.top(); evenNumbers.pop();

      a = getRectifiedIndex(deleteIndex1, deleteIndex2, a);
      b = getRectifiedIndex(deleteIndex1, deleteIndex2, b);
      
      cout<<a<<" "<<b<<"\n";
    }
     
  }
  
  return 0;
}