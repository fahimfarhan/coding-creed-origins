#include <bits/stdc++.h>

using namespace std;

int main(){ 

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a,b,c,d,e;
    while(cin>>a>>b){
        c = a|b;
        d = a&b;
        e = c|d;
        cout<<e<<"\n";
    }
    return 0;
}