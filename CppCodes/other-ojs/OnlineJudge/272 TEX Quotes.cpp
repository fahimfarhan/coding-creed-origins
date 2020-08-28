#include <bits/stdc++.h>
#include <ios>
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s;
    char ch;
    bool toogle = true;

    while(getline(cin, s)) {
        for(int i=0; i<s.size(); i++) {
            ch = s[i];
            if(ch == '"') {
                if(toogle) {
                    cout<<"``";
                }else{
                    cout<<"''";
                }
                toogle = !toogle;
            }else{
                cout<<ch;
            }
        }
        cout<<"\n";
    }
    return 0;
}