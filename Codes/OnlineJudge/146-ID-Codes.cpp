#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s;
    string t;
    while(getline(cin, s)) {
        if(s == "#") {  break;  }
        else{
            t = s;
            sort(t.begin(), t.end(), greater<char>());
            if(s == t) {
                cout<<"No Successor\n";
            }else{
                next_permutation(s.begin(), s.end());
                cout<<s<<"\n";
            }

        }
    }

    return 0;
}