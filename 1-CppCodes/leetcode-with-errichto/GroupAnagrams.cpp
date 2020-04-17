#include <bits/stdc++.h>

using namespace std;

vector<vector<string>> groupAnagramsUsingMap(vector<string>& strs) {
    unordered_map<string, vector<string> > mp;
    for(string s : strs){
        string s2 = s;
        sort(s2.begin(),s2.end());
        mp[s2].push_back(s);
    }        
    vector<vector<string> > v;
    for(auto x : mp){
        v.push_back(x.second);
    }
    return v;
}

// idea by Errichto
vector<vector<string>> groupAnagramsUsingSort(vector<string>& strs) {
    vector< pair<string,string> > v1;
    for(string s : strs){
        string canonicalString = s;
        sort(canonicalString.begin(), canonicalString.end());
        v1.push_back({canonicalString, s});
    }

    sort(v1.begin(), v1.end());

    vector<vector<string> > result;
    vector<string> v;
    for(int i=0; i<v1.size(); i++){
        pair<string, string> p = v1[i];
        if(v.empty()){
            v.push_back(p.second);
        }else{
            int j = i-1;
            if(v1[j].first != p.first){
                result.push_back(v);
                v.clear();
            }      
            v.push_back(p.second);
        }
    }

    if(!v.empty()) {
        result.push_back(v);
    }

    return result;
}

int main(){

    return 0;
}