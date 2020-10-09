#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--) {
        string ind, num;
        vector<int>index;
        vector<string> ans;

        cin.ignore();

        getline(cin, ind); // the blank line
        getline(cin, ind); // the actual 1st line of each test case
        // cerr<<"line 1\n"<<ind<<"\n";
        stringstream s;
        s << ind;
        int x;
        while(s >> x) {
            index.push_back(x);
        }

        // for(int i=0;i<index.size(); i++) {
        //     cerr<<"line2 "<<index[i];
        // }

        ans.resize(index.size()+1);

        string fnum;
        for(int i=0; i<index.size(); i++) {
            cin>>fnum;
            ans[index[i] - 1] = fnum;
        }

        for(int i=0; i<ans.size()-1; i++) {
            cout<<ans[i]<<"\n";
        }cout<<ans[ans.size()-1];

        if(T) {
            cout<<"\n";
        }
    }

    return 0;
}