/*************************************************************************
  SPDX-License-Identifier: MIT
  Copyright (c) 2020 Qazi Fahim Farhan (@fahimfarhan)
  May the CodeForces be with you!
 ************************************************************************/

#include <cctype>
#include <ios>
#include <iostream>
#include <climits>  // this includes INT_MIN, INT_MAX, ... ...
// #include <sstream>
// #include <cstdio>
// #include <cmath>
// #include <cstring>
// #include <cctype>
// #include <string>
#include <string>
#include <vector>
// #include <list>
// #include <set>
// #include <unordered_set>
// #include <map>
#include <unordered_map>
// #include <queue>
// #include <stack>
#include <algorithm>
// #include <functional>
#include <iomanip>      // std::setprecision


using namespace std;

#define PI 2*acos(0)

//typedef long long int ll;
 #define ll long long int
// other popular ones=> int64_t, uint64_t => use for 10^18
ll MOD = 1e9+7;

// int n,m;
vector<int> *g;
bool *isvisited;

bool komparator(const pair<int, string>& a, const pair<int, string>& b) {
  if(a.first < b.first) {
    return true;
  }else if(a.first == b.first) {
    return (a.second < b.second);
  }
  return false;
}

string toUpperCase(const string& input) {
  string output = "";
  for(int i=0; i<input.size(); i++) {
    output += toupper(input[i]);
  }
  return  output;
}

void FastIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int main(int argc, char const *argv[]){
  /* code */
  FastIO();

  int T;
  string title;
  int n,m,b;
  string ingredient; int c;
  string recipie;
  int k;
  string requirement; int x;

  unordered_map<string, int> ingredients;
  // unordered_map<string, int> requirements;
  vector<pair<int, string> > availableMenu;

  cin>>T;
  for(int testKase = 1; testKase <= T; testKase++) {
    getline(cin, title);
    getline(cin, title);
    // cerr<<"title "<<title<<"\n";
    cin>>m>>n>>b;
    for(int i=0; i<m; i++) {
      cin>>ingredient>>c;
      ingredients[ingredient] = c;
    }
    for(int i=0; i<n; i++) {
      getline(cin, recipie); // empty space after last ingredient cost
      getline(cin, recipie); // this is the actual recipie 
      // cerr<<"recipie "<<recipie<<"\n";
      cin>>k;
      int kost = 0;
      for(int j=0; j<k; j++) {
        cin>>requirement>>x;
        // requirements[requirement] = x;
        kost+= x*ingredients[requirement];
      }

      if(kost <= b) {
        availableMenu.push_back({kost, recipie});
      }
    }
    if(!availableMenu.empty()) {
      sort(availableMenu.begin(), availableMenu.end(), komparator);
    }

    title = toUpperCase(title);
    cout<<title<<"\n";
    if(availableMenu.empty()) {
      cout<<"Too expensive!\n";
    }else{
      for(pair<int, string> someMenu : availableMenu) {
        cout<<someMenu.second<<"\n";
      }
    }
    cout<<"\n";
    // if(testKase < T) {  cout<<"\n"; }
    
    availableMenu.clear();
    ingredients.clear();
  }
  return 0;
}
