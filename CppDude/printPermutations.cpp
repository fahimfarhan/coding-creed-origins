#include <bits/stdc++.h>

using namespace std;

int main(){
    int npr = 24;
    vector<int> v;
    for(int i=1; i<=4; i++){
        v.push_back(5-i);
    }

    for(int j=0; j<npr; j++){
        cout<<"j="<<j<<" : ";
        for(int i=0; i<4; i++){
            //v.push_back(i);
            cout<<v[i]<<" ";
        }printf("\n");
    next_permutation(v.begin(), v.end());
    }
    
}