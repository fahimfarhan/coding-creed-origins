#include <bits/stdc++.h>

using namespace std;

int main(){
    int ans;
    for(int i=0; i<100; i++){
        ans = i & (-i);
        //cout<<i<<" "<<ans<<"\n";
        printf("%d %d %x %x\n",i,ans,i,ans);
    }
}