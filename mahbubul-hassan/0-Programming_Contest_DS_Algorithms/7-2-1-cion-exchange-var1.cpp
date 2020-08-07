#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

#define ll long long int

#define NUM_OF_COINS 10

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


// int n,m;
vector<int> *g;
bool *isvisited;

int c[NUM_OF_COINS] = {1,2,3,5,7,11,13,16,17,19};

short *dp;
int N;

bool f(int n){
    int ret=0;
    if(n<0){    return ret; }
    else if(dp[n]>-1){    return dp[n]; }
    else{
        int m=0;
        for(int i=0; i<NUM_OF_COINS; i++){
            m = n - c[i];
            ret = f(m);
            if(ret==1){    break;  } 
        }
        dp[n]=ret;
        return dp[n];
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    /*
    cout << setprecision(8);
    cout << num1 << endl;
    */
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;

    dp = new short[N+1];
    for(int i=0; i<=N; i++){    dp[i] = -1;  }
    dp[0]=1;

    int ans = f(N);

    

    if(!dp)delete[] dp;

    return 0;
}
/*
    int     -2147483648 2147483647
    short   -32768      32767
*/