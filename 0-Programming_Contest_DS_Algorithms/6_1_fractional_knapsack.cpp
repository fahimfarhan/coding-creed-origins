#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

vector<pii> p;
bool mycomparator(pii i, pii j){
    // i.2nd/i.1st > j.2nd/j.1st
    // => i.2ndxj.1st > j.2ndxxi.1st

    return i.second*j.first > i.first*j.second;

    // return true;
}

int main()
{
    int n;
    cin>>n;
    
    for(int i=0; i<n; i++){
        int w,c; cin>>w>>c;
        p.push_back(pii(w,c));
    }

    sort(p.begin(), p.end(), mycomparator());

    int ans = 0, W = 100;
    for(int i=0; i<n; i++){
        int temp = min(W, p[i].first);
        W-=temp;
        ans+=temp*p[i].second;
        
    }

    cout<<ans<<"\n";
    return 0;
}