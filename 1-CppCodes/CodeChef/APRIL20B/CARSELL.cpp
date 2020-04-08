#include <bits/stdc++.h>

#define ll long long int
#define MOD 1000000007

using namespace std;

int main(){
    ll T, N, *A, result;

    cin>>T;
    while(T--){
        cin>>N;
        A = new ll[N+1];
        for(int i=0; i<N; i++){ cin>>A[i];  }
        sort(A,A+N);
        result = 0;
        ll j=-1;
        for(ll i=N-1; i>=0; i--){
            j++;
            A[i] = max(A[i]-j, (ll)0);
            if(A[i] == 0){  break; }
            result = (result+A[i])%MOD;
            // cout<<result<<" ";
        }
        cout<<result<<"\n";
        delete[] A;
    }
    return 0;
}