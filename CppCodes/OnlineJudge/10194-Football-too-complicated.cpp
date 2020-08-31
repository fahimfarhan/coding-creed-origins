/** @brief: too complicated, I don't understand some of the questions , eg, `goal against` :/ */
#include <bits/stdc++.h>

using namespace std;

class Item{
public:
    string name;
    int attrs[9] = {0};


    Item(string teamname="") {
        name = teamname;
        for(int i=0; i<9; i++) {    attrs[i] = 0; }
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, T, G;
    string s;
    Item *teams;
    unordered_map<string, int>  mp;
    
    cin>>N;
    while(N--) {
        cin>>T;
        teams = new Item[T+1];
        string teamName;
        getline(cin,teamName);
        for(int i=0; i<T; i++) {    // cz crazy uva style input
            getline(cin, teamName);
            cerr<<"Debug "<<teamName<<"\n";
            teams[0] = Item(teamName);
            mp[teamName] = i;
        }

        cin>>G;
        getline(cin, s);
        for(int i=0; i<G; i++) {
            getline(cin, s);
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

            int team1Pos = mp[team1];
            int team2Pos = mp[team2];
        }

        mp.clear();
        delete[] teams;
    }

    return 0;
}