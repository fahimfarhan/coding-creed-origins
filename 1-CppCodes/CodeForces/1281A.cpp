#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, len;
    string s;
    cin>>t;
    while(t--){
        cin>>s;
        len = s.size();
        if((s[len-2] == 'p') && (s[len-1] == 'o')){
            cout<<"FILIPINO\n";
            // mnida
        }else if((len >=5) && (s[len-1] == 'a') && (s[len-2] == 'd') && (s[len-3] == 'i') && (s[len-4] == 'n') && (s[len-5] == 'm')){ // mnida
            cout<<"KOREAN\n";
        }else{
            cout<<"JAPANESE\n";
        }
    }
}