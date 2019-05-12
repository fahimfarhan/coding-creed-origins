#include <bits/stdc++.h>

using namespace std;

int f(int x){
    int a,t,mycount=1;
    a = x;
    while(true){
        if(a==1){  return mycount; }
        else if( (a&1) == 1){
            a = a+(a<<1)+1;
        }else{ a = a>>1; }
        mycount++;
    }
    return 0;
}

int main()
{
    int i,j,k,l,ans=INT_MIN,temp;
    while(cin>>i>>j){
        ans=INT_MIN;
        k = min(i,j); l = max(i,j);
        for(int m=k; m<=l; m++){
            temp = f(m);
            ans = max(ans,temp);
        }
        cout<<i<<" "<<j<<" "<<ans<<"\n";
    }

    return 0;
}