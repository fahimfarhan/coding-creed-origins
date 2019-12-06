#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    vector< pair<int,int> > v;

    int t,n,a, minimus, maximus, m;
    cin>>t;
    while(t--){
        v.clear();
        cin>>n;
        for(int i=1; i<=n; i++){
            cin>>a;
            v.push_back({a,i});
        }

        sort(v.begin(), v.end());

        string ans = "";
        minimus = n+1; maximus = 0;
        for(int i=1; i<=n; i++){
            m = v[i-1].second;
            minimus = min(minimus,m);
            maximus = max(maximus,m);

            if(maximus-minimus+1 == i){    ans+="1";    }
            else{  ans+="0";   }
        }

        cout<<ans<<"\n";
    }

    return 0;
}