#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    int a[n+1];

    for(int i=0; i<n; i++){ cin>>a[i];  }

    vector<int> pos;
    for(int i=0; i<n; i++){
        int x = a[i];
        while(x>0){ pos.push_back(x); x=(x>>1);    }
    }

    int minimus = INT_MAX;
    
    for(auto res:pos){
        vector<int> count;
        for(int i=0; i<n; i++){
            int x = a[i];
            int curr = 0;
            while(x>res){
                x=(x>>1);
                curr++;
            }
            if(x == res){   count.push_back(curr);  }
        }
        if(count.size() >= k ){
            sort(count.begin(), count.end());
            int temp = accumulate(count.begin(), count.begin()+k, 0);
            minimus = min(minimus, temp);
        }
    }

    cout<<minimus<<"\n";
    
    return 0;
}