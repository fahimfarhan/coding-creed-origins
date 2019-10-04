#include <bits/stdc++.h>
#define ll int
using namespace std;

int main(){

    ll n;
    cin>>n;
    ll a[n][n];

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>a[i][j];
        }
    }

    a[0][0] = a[0][1]*a[0][2]/a[1][2];
    a[0][0] = sqrt(a[0][0]);

    cout<<a[0][0]<<" ";
    for(int i=1; i<n; i++){ cout<<a[0][i]/a[0][0]<<" "; }
    cout<<"\n";

    return 0;
}