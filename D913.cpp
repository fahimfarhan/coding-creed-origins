#include <bits/stdc++.h>

using namespace std;

class D913{
private:
    int n;
    int64_t T,score;
    int a,t, count;
    vector< pair<int,pair<int,int> > > v;
    vector<int> order;
public:
    D913(){
        cin>>n>>T;
        //a = new int[n+1];
        //t = new int[n+1];
        for(int i=0; i<n; i++){
            cin>>a>>t;
            v.push_back(make_pair(t,make_pair(a,i+1)));
        }
        count = 0;
        sort(v.begin(),v.end());
        int k=0;
        score = 0;
        while(true){
            if(v[k].first<=T){
                T = T-v[k].first;
                int u = v[k].second.second;
                order.push_back(u);
                k++;
            }else break;
        }

        for(int i=0; i<k; i++){
            a = v[i].second.first;
             if (k<=a)
            {   score++;    }
        }

        cout<<score<<endl;
        cout<<k<<endl;
        for(int i=0; i<order.size(); i++){
            cout<<order[i]<<" ";
        }cout<<endl;


    }
    ~D913() {}
};
int main()
{
    D913 d913;
    return 0;
}