#include <bits/stdc++.h>

using namespace std;

#define ll long long int 
#define M 1000000007

ll n,m,nCr[1001][1001],ans=1,s[1001],mypow[1001];
int main(){
    cin >> n >> m;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=i;j++){
            if(j==0 || j==i) nCr[i][j]=1;
            else nCr[i][j]=(nCr[i-1][j-1]+nCr[i-1][j])%M;
        }
    }
    mypow[0]=1;mypow[1]=1;
    for(int i=2;i<=n;i++) mypow[i]=(mypow[i-1]<<1)%M;
    for(int i=0;i<m;i++) cin >> s[i];
    sort(s,s+m);
    ll cnt=0,tmp;
    for(int i=0;i<m;i++){
        if(i==0) tmp=s[i]-1;
        else{
            tmp=s[i]-s[i-1]-1;
            ans=(ans*mypow[tmp])%M;
        }
        cnt+=tmp;
        ans=(ans*nCr[cnt][tmp])%M;
    }
    temp=n-s[m-1];
    cnt+=temp;
    ans=(ans*nCr[cnt][temp])%M;
    cout << ans << endl;
    return 0;
}