#include <bits/stdc++.h>
using namespace std;

bool checkValidString(string s) {
    int balanced = 0;
    int n = s.size();
    for(int i=0; i<n; i++) {
        if(s[i] == '(' || s[i] == '*'){ balanced++; }
        else{
            balanced--;
            if(balanced == -1) return false;
        }
    }        

    balanced = 0;
    for(int i=n-1; i>=0; i--) {
        if(s[i] == ')' || s[i] == '*'){ balanced++; }
        else{
            balanced--;
            if(balanced == -1) return false;
        }
    }

    return true;
}


int main () {
    
    return 0;
}