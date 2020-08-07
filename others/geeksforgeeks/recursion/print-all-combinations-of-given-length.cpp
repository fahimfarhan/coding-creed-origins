#include<bits/stdc++.h>

using namespace std;

string s="abcdefg";

void recursion(const string& prefix, const int& k){
    if(k==0){   cout<<prefix<<"\n"; return; }
    string nextprefix = "";

    int n=s.size();
    int k1=k-1;
    for(int i=0; i<n; i++){
        nextprefix="";
        nextprefix = prefix + s[i];
        recursion(nextprefix, k1);
    }
}

int main(){
    recursion("", 3);
    return 0;
}