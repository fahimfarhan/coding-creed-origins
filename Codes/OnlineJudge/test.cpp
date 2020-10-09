#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
    string s = "Brazil#2@1#Scotland";
    // getline(cin, s);
            int hashPos[2] = {0};
            int alphaPos = 0;
            int j = 0;

            for(int k=0; k<s.size();k++) {
                if(s[k] == '#'){
                    hashPos[j] = k;
                    j++;
                    if(j == 2) {    break; }
                }else if(s[k] == '@') {
                    alphaPos = k;
                }
            }

            // get team 1 name
            string team1 = s.substr(0, hashPos[0]);
            // get team 1 score
            string score1 = s.substr(hashPos[0]+1, alphaPos - hashPos[0] - 1);
            // get team 2 score
            string score2 = s.substr(alphaPos+1, hashPos[1] - alphaPos - 1);
            // get team 2 name
            string team2 = s.substr(hashPos[1]+1);

            string a = s.substr(hashPos[0]+1, hashPos[1]-hashPos[0]-1);
            cout<<a<<"\n";
            cout<<team1<<" "<<score1<<"\n";
            cout<<team2<<" "<<score2<<"\n";

    return 0;
}

