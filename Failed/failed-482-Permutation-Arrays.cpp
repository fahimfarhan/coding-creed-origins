/**
(simple array manipulation)
*/

#include<bits/stdc++.h>
#include <sstream>
#include <string>

#define ll long long int

using namespace std;



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T;
    vector<int> v;
    float *f;
    
    cin>>T;

    while(T--) {
        string line;
        getline(cin, line);

        cerr<<"line = "<<line<<"\n";
        stringstream ss(line);

        int m;
        while(ss >> m) {
            v.push_back(m);
        }

        for(int i=0; i<v.size(); i++) {
            cerr<<v[i]<<" ";
        }cerr<<"\n";

        f = new float[v.size()+1];

        for(int i=0; i<v.size(); i++) {
            cin>>f[v[i]-1]; 
        }

        for(int i=0; i<v.size(); i++) {
            cout<<f[i]<<"\n";
        } 

        delete[] f;
    }

    return 0;
}