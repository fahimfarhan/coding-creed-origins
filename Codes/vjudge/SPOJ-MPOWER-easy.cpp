#include<bits/stdc++.h>
#include <ios>
using namespace std;

#define ll long long int

inline ll calcPower(const ll& base, const ll& power, const ll& mod) {
  if(power == 0) {
    return 1;
  }
  if(power == 1) {
    return base;
  }
  
  ll result = 1;
  ll m = power >> 1;
  result = calcPower(base, m, mod);
  result = (result * result) % mod;
  if((power&1) == 1){
    result = (result * base) % mod;
  }
  return result;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cin.tie(0);

  ll T, base, power, mod;
  
  cin>>T;
  
  while(T--) {
    cin>>base>>power>>mod;
    cout<<calcPower(base, power, mod)<<"\n";
  }
  
  return 0;
}