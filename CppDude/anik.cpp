#include<bits/stdc++.h>
using namespace std;
vector< pair<int,int> >v;
vector<int>indx;

int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        int p; scanf("%d",&p);
        v.push_back({-p,i});
    }

    sort(v.begin(),v.end());
    int Sum=0;

    indx.push_back(0);
    for(int i=0;i<k;i++){
        Sum-=v[i].first;
        indx.push_back(v[i].second);
    }

    sort(indx.begin(),indx.end());
    printf("%d\n",Sum);
    for(int i=1;i<k;i++) printf("%d ",indx[i]-indx[i-1]);
    printf("%d",n-indx[k-1]);
}