#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin.tie(0);

    int T; string n;
    cin>>T;
    for(int t=1; t<=T; t++){
        cin>>n;
        for(int i=n.size()-1; i>0; i--){
            if( n[i] < n[i-1]){
                n[i-1]--;
                for(int j=i; j<n.size(); j++){    n[j]='9';   }
            }
        }
        cout<<"Case #"<<t<<": "<<stoll(n)<<"\n";
    }

    return 0;
}