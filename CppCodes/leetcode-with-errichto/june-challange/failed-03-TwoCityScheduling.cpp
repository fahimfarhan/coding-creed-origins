#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<pair<int,pair<int,char> > > v;
        int N = costs.size();
        vector<bool> isTaken;

        for(int i=0; i<N; i++) {    isTaken.push_back(false);   }
        N = N/2;

        for(int i=0; i < costs.size(); i++) {
            v.push_back({costs[i][0], {i,'A'} });
            v.push_back({costs[i][1], {i,'B'} });
        }   

        sort(v.begin(), v.end());

        for(int i=0; i<v.size(); i++) {
            cout<<v[i].first<<" "<<v[i].second.first<<" "<<v[i].second.second<<"\n";
        }

        int kostA = 0, kostB = 0, kountA = 0, kountB = 0;
        int kost = 0;   

        cout<<v.size()<<" = v.size()\n";
        for(int i=0; i<v.size(); i++) {
            int index = v[i].second.first;
            if(isTaken[index] == false) {
                if( ( v[i].second.second == 'A') && (kountA <N) ) {
                    kost = kost + v[i].first;
                    kountA++;
                }else if( (v[i].second.second == 'B') && (kountB <N) ){
                    kost = kost + v[i].first;
                    kountB++;
                }
                // isTaken[index] = true;
            }
        }

        // cout<<"kostA kostB = "<<kostA<<" "<<kostB<<"\n";
        // int kost = kostA + kostB;
        return kost;
    }
};

int main() {

// [[259,770],[448,54],[926,667],[184,139],[840,118],[577,469]]
    Solution s;

    vector<vector<int> > v;
    v.push_back({448,54});
    v.push_back({926,667});
    v.push_back({184,139});
    v.push_back({840,118});
    v.push_back({577,469});

    cout<<s.twoCitySchedCost(v)<<"\n";
    return 0;
}