#include <bits/stdc++.h>
#define N 100
#define M 6
using namespace std;

bool *dp;
bool *visited;
bool *istaken;
int coin[M] = {3,5,7,10,13,20};

bool f(int n){
    if(visited[n]){ return dp[n];   }
    else{
        for(int i=0; i<M; i++){
            if( (n-coin[i]>=0) && (istaken[i] == false) ){
                istaken[i] = true;
                dp[n] = dp[n]|f(n-coin[i]);
                istaken[i] = false;
            }
            if(dp[n]){  break; }
        }
        visited[n] = true;
        return dp[n];
    }


    return true;
}



int main()
{
    dp = new bool[N+1];
    visited = new bool[N+1];
    istaken = new bool[M+1];
    for(int i=0; i<M; i++){ istaken[i] = false; }
    for(int i=1; i<=N; i++){    dp[i] = false; visited[i] = false;   }

    dp[0] = true;
    visited[0] = true;

    cout<<"25 : "<<f(25)<<"\n";
    cout<<"20 : "<<f(20)<<"\n";
    cout<<"11 : "<<f(11)<<"\n";
    cout<<"43 : "<<f(43)<<"\n";

    if(!dp)delete[] dp;
    if(!visited)delete[] visited;
    if(!istaken)delete[] istaken;
    return 0;
}