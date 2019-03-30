#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int f(int a, ll b){
    int ret=0;
    if(b==0){   return 1; }
    if(b == 1){ return a; }
    ll h = b>>1;
    ret = f(a,h);
    ret = ret*ret;
    if(b&1){    ret = ret*a; }
    // ret*ret*a => 22*22*20 = 9680 , looks reasonably small :/
    ret = ret%10;
    return ret;
}

int main(int argc, char const *argv[]){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T,a,c;ll b;
    cin>>T;
    while(T--){
        cin>>a>>b;
        c = f(a,b)%10;
        cout<<c<<"\n";
    }
    return 0;
}