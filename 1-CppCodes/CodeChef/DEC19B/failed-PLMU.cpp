#include <bits/stdc++.h>

using namespace std;

#define ll long long int

int main(){

    int T, N;
    ll a, kount, ans, one = 1, two = 2;
    ll A[40000];
    cin>>T; 
    while(T--){
        cin>>N;
        
        for(int i=0; i<N; i++){
            cin>>A[i];
        }
        a = 0; kount = 0;
        for(int i=0; i<N; i++){
            if(A[i] == 2){kount++;}
        }

        ans = kount*(kount-1)/2;
        cout<<ans<<"\n";

    }
    return 0;
}