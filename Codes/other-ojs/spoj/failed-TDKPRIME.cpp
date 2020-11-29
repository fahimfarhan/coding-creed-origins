#include <bits/stdc++.h>
#include <climits>
#include <ios>
using namespace std;

#define N   90000000+1
          // 2147483647
#define ll unsigned int

void fastIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

bool isNotPrime[N]; //  = {true};  
// todo: Never init bool arrays! 
// cz they take a lot of time! by default the bool array is false
vector<ll> prime;

void preprocessing() {
  isNotPrime[0] = true;
  isNotPrime[1] = true;

  // for(unsigned int i=4; i<=N; i+=2) {
  //   isNotPrime[i] = true;
  // }  
  prime.push_back(2);

  for(unsigned int j=3; j*j<=N; j+=2) {
    for(unsigned int i = 2*j; i*i<=N; i+=j) {
      isNotPrime[i] = true;
    }
    if(!isNotPrime[j]) {
      prime.push_back(j);
      // if(prime.size() >= 5000000) { break; }
    }
  }

  // for(unsigned int i=2; i<=N; i++) {
  //   if(!isNotPrime[i]) {  prime.push_back(i); }
  // }
}

int main() {
  fastIO();

  ll Q, K;
  cin>>Q;

  preprocessing();

  while(Q--) {
    cin>>K;
    cout<<prime[K-1]<<"\n";
  }

  // cout<<INT_MAX<<"\n";

  return 0;
}