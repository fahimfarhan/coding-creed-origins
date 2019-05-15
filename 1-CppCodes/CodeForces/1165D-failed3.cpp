#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> u,v;

int main()
{
    int t;
    cin>>t;
    for(int k=0; k<t; k++){
        int n;
        cin>>n;
        v.clear();
        u.clear();
        ll minimus, maximus,x;
        
        for(int i=0; i<n; i++){
            cin>>x;
            v.push_back(x);
            if(i==0){
                minimus = x; maximus = x;
            }else{
                minimus = min(minimus,x);
                maximus = max(maximus,x);
            }
        }

        ll d = minimus*maximus;

        for(ll i=0; i*i<=d; i++){
            if( (d%i) == 0){
                ll a = i, b = d/i;
                u.push_back(a);
                if(a!=b){   u.push_back(b);    }
            }
        }

        sort(u.begin(), u.end());
        sort(v.begin(), v.end());
        
        if(u==v){
            cout<<d<<"\n";
        }else{
            cout<<"-1\n";
        }

        
    }

    return 0;
}