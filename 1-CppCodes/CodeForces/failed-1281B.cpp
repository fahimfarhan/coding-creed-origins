#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;

    int pos;
    char minimus, temp;
    string s, c;
    cin>>t;
    while(t--){
        cin>>s>>c;
        minimus = 'Z';
        for(int i=1; i<s.size(); i++){
            if(s[i]<=minimus){   minimus = s[i]; pos = i;    }
        }
        for(int i=0; i<s.size(); i++){
            if(s[i]>minimus){
                temp = s[i];
                s[i] = s[pos];
                s[pos] = temp;
                break;
            }
        }
        int j = 0;
        int minimusLen = min(s.size() , c.size());
        while( (j<minimusLen) && (s[j] == c[j])){
            j++;
        }
        if(j<minimusLen-1){j = j+1;}
;        if(s[j] < c[j]){
            cout<<s<<"\n";
        }else{
            cout<<"---\n";
            // cout<<s<<" "<<c<<"\n";
        }
    }
    return 0;
}
