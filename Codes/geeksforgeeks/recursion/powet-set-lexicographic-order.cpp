#include <bits/stdc++.h>

using namespace std;

string s;
int n;

void recursion(int j, string curr){
    for(int i=j; i<n; i++){
        string next = curr+s[i];
        cout<<next<<"\n";
        recursion( (i+1), next);
    }
}

int main(){
    s = "abc";
    n = s.size();
    recursion(0,"");

    return 0;
}