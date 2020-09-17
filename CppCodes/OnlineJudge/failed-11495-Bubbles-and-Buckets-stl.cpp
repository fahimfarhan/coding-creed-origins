/* SPDX-License-Identifier: MIT */
/* Copyright (c) 2020 Qazi Fahim Farhan (@fahimfarhan) */
/* May the CodeForces be with you! */
#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

#define PI 2*acos(0)
#define ll long long int
ll MOD = 1e9+7;
vector<int> *g;
bool *isvisited;

ll player = 0;

bool comparator(const int& i,const int& j) {
    if(i<=j) {
        player++;
        return true;
    }else{

        return false;
    }
}

int main(int argc, char const *argv[]){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll N, *a, *b;
    ll one = 1;
    while(true) {
        cin>>N;
        if(N==0) {  break;  }
        a = new ll[N+1];
        for(int i=0; i<N; i++) {    cin>>a[i];  }
        
        player = 0;
        sort(a,a+N, comparator);
        cerr<<player<<"\n";
        if( (player & one) == one) {
            cout<<"Marcelo\n";
        }else{
            cout<<"Carlos\n";
        }    

        delete[] a;
    }
    return 0;
}
