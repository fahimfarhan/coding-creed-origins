#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T,k, count, tc; string s;
    cin>>T;
    tc = 0;
    while(T--){
        tc++;
        cin>>s>>k;
        count=0;
        for(int i=0; i<=s.size()-k; i++){
            if(s[i] == '-'){
                for(int j=0; j<k; j++){
                    if(s[i+j]=='+'){    s[i+j] = '-';   }
                    else{  s[i+j]='+'; }
                }
                count++;
            }
        }

        for(int i=s.size()-k+1; i<s.size(); i++){
            if(s[i] == '-'){    count=-1; break; }
        }

        cout<<"Case #"<<tc<<": ";
        if(count==-1){  cout<<"IMPOSSIBLE\n";   }
        else{   cout<<count<<"\n";  }

    }
    return 0;
}