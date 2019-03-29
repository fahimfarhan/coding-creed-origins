#include <bits/stdc++.h>

using namespace std;

int *dp;
long long int *ways;
int coin[4] = {2,4,7,9};
int main()
{
    int x;
    cin>>x;
    dp = new int[105];
    ways = new long long int[105];
    dp[0] = 1;
    ways[0] = 1;
    for(int i=01; i<=100; i++){
        for(int j=0; j<4; j++){
            if(i-coin[j]>=0){
                dp[i] |= dp[i-coin[j]];
                ways[i]+=ways[i-coin[j]];
            }
        }
    }

for(int i=0; i<=100; i++){
    cout<<ways[i]<<" ";
}
    cout<<"\n------\n"<<ways[x]<<"\n";

    if(!dp)delete[] dp;
    if(!ways)delete[] ways;
    return 0;
}
