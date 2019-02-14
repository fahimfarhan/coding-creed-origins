#include <bits/stdc++.h>

using namespace std;

int *dp;
int coin[4] = {2,4,7,9};
int main()
{
    int x;
    cin>>x;
    dp = new int[105];
    dp[0] = 1;
    for(int i=01; i<=100; i++){
        for(int j=0; j<4; j++){
            if(i-coin[j]>=0){
                dp[i] |= dp[i-coin[j]];
            }
        }
    }

for(int i=0; i<=100; i++){
    cout<<dp[i]<<" ";
}
    cout<<"\n"<<dp[x]<<"\n";

    if(!dp)delete[] dp;
    return 0;
}
