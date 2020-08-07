#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("sort.in","r",stdin);
    freopen("output.txt","w",stdout);
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    vector<int> v;

    cin>>n;
    for(int i=0; i<n; i++) {
        cin>>m;
        v.push_back(m);
    }
    sort(v.begin(), v.end());
    for(int i=0; i<n; i++) {
        cout<<v[i]<<" ";
    }
    return 0;
}