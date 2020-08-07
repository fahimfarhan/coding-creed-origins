#include <bits/stdc++.h>
using namespace std;

bool backspaceCompare(string S, string T) {
    int p1=0, p2=0;
    for(int i=0; i<S.size(); i++){
        if(S[i] == '#'){
            p1= p1-1;
            p1 = max(p1,0);
        }else{
            S[p1] = S[i];
            p1++;
        }
    }

    S = S.substr(0,p1);

    for(int i=0; i<T.size(); i++){
        if(T[i] == '#'){
            p2= p2-1;
            p2 = max(p2,0);
        }else{
            T[p2] = T[i];
            p2++;
        }
    }

    T = T.substr(0,p2);

    if(S == T){ return true; }
    return false;
}

int main(){

    cout<<backspaceCompare("ab#c", "ad#c");
    return 0;
}
