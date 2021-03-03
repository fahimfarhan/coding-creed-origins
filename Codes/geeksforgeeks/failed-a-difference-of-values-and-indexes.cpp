/* Author : Qazi Fahim Farhan (@fahimfarhan) */
/* May the CodeForces be with you! */

#include <bits/stdc++.h>


using namespace std;

#define PI 2*acos(0)

//typedef long long int ll;
 #define ll long long int
// other popular ones=> int64_t, uint64_t => use for 10^18
ll MOD = 1e9+7;

int main(int argc, char const *argv[])
{
    /* code */
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    /*
    std::cout << std::fixed;
    std::cout << std::setprecision(10);
    cout << num1 << endl;
    */
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll T, N, a;
    cin>>T;
    while(T--) {
      vector<ll> v;
      cin>>N;
      for(int i=0; i<N; i++) {
        cin>>a;
        v.push_back(a);
      }

      ll maximus = INT_MIN ,temp;
      for(int i=0; i<N-1; i++) {
        for(int j=i+1; j<N; j++) {
          temp = abs(v[i] - v[j]) + abs(i-j);
          maximus = max(temp, maximus);
        }
      }
      cout<<maximus<<"\n";
    }

    return 0;
}