#include <bits/stdc++.h>

using namespace std;

int main() {
    string input = "ababba";
    string s = input + "$";

    vector<string> suffixes;

    string t = "";
    for(int i=s.size()-1; i>=0; i--) {
        t = s[i] + t;
        suffixes.push_back(t); 
    }

    for(int i=0; i<suffixes.size(); i++) {
        cout<<suffixes[i]<<"\n";
    }
    cout<<"\n-------------------\n";

    sort(suffixes.begin(), suffixes.end());
    
    for(int i=0; i<suffixes.size(); i++) {
        cout<<suffixes[i]<<"\n";
    }
    cout<<"\n-------------------\n";

    return 0;
}