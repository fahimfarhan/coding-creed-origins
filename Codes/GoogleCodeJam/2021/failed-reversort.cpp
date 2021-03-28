#include <bits/stdc++.h>
using namespace std;

int T, N;
int *L;
map<int, int> mp;


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);



  cin>>T;
  for(int t=1; t<=T; t++) {
    cin>>N;
    L = new int[N+1];
    // mp = new int[N+1];
    for(int i=1; i<=N; i++) {
      cin>>L[i];
    }

    for(int i=1; i<=N; i++) {
      mp[L[i]] = i;
    }

    int kost = 0;

    for(int i=1; i<=N; i++) {
      for(int j=1; j<i; j++) {
        mp[i] = N - mp[i] + j;
      }
      if(mp[i] != i) {
        kost += (mp[i] - i + 1);
      }
    }

    cout<<"Case #"<<t<<": "<<kost<<"\n";



    delete[] L;
    mp.clear();
  }

  return 0;
}