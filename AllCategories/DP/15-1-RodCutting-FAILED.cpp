#include <bits/stdc++.h>

using namespace std;

#define M_INF -9999
int p[] = {0,1,5,8,9,10,17,17,20,24,30};
int dp[11];

int recurrCutRod(int n){
    if(n==0){   return 0; }
    int q = M_INF;

    for(int i=1; i<=n; i++){
        q = max(q,p[i]+recurrCutRod(n-i));
    }
    return q;

}


int dpCutRod(int n){
    cout<<"DEBUG: "<<n<<"\n";
    if(n==0){   return 0; }
    if(dp[n]!=-1){   return dp[n];}
    int q = M_INF;

    for(int i=1; i<=n; i++){
        q = max(q,dpCutRod(i));
    }
    return q;

}
int main()
{
    //for(int i=0; i<11; i++){
        for(int j=0; j<11; j++){
            if( j==0){   dp[j] = 0; }
            else { dp[j]  = -1; }
        }
    //}

    cout<<"recurrence\n";
    for(int i=1; i<11; i++){    cout<<recurrCutRod(i)<<" "; }
    //cout<<"\nDP\n";
    //dpCutRod(10);
    //for(int i=1; i<11; i++){    cout<<dpCutRod(i)<<" "; }

    return 0;
}