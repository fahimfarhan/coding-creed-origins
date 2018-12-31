#include <bits/stdc++.h>
using namespace std;

void takeInput(){
    int totalPartition;
    string s;
    vector<string> vs;
    int n; // num of nodes
    vector<int> *g;
    bool *isvisited;
    int *inedge, *outedge;
    map< pair<int,int> , int > CE;
  cin>>totalPartition;
  while(getline(cin, s)){
    if(s!="")
      vs.push_back(s);
  }
  n = vs.size();
  g = new vector<int>[n+1];
  isvisited = new bool[n+1];
  inedge = new int[n+1];
  outedge = new int[n+1];

  for(int i=0; i<=n; i++){  isvisited[i] = false; inedge[i] = 0; outedge[i] = 0; }

  for(int i=0; i<vs.size(); i++){
      istringstream iss(vs[i]);

      int i1=0;
      string a = "";
      int u,v;
      while(iss >> a){
        i1++;
        if(i1==1){ u = stoi(a); }//cout<<a<<" : ";}
        if(i1>=3){ v = stoi(a); g[u].push_back(v); inedge[v]++; outedge[u]++; CE[{u,v}] = 1;  }//cout<<a<<" "; }
        //cout<<a<<" ";

      } //cout<<"\n";
  }
}
