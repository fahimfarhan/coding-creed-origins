#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Chefzot{
private:
    ll N, A,count,ans;
public:
    Chefzot(){
        count=0; ans=0;
        scanf("%I64d",&N);
        
        for(ll i=0; i<N;i++){
            scanf("%I64d",&A);
            if(A>0){  count++;  }
            else{ count=0; }
            if(count>ans){ans=count;}
        }

        printf("%I64d",ans);
    }
    ~Chefzot() {}
};
int main(){
    Chefzot chefzot;
    return 0;
}