#ifdef _WIN32

#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>

#else

#include <bits/stdc++.h>

#endif

using namespace std;

#define PI 2*acos(0)

typedef long long int ll;
// #define ll long long int
// other popular ones=> int64_t, uint64_t => use for 10^18
ll MODULO = 1e9+7;

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


// int n,m;s
vector<int> *g;
bool *isvisited;

int a[65][65], lenOfSeq[65][65];
int T,n,m, nm, number;
ll ans;

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
    cin>>T;
    for(int t=1; t<=T; t++){
        cin>>n>>m;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                cin>>a[i][j];
            }
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if((j==1) || (a[i][j]!=a[i][j-1])){ lenOfSeq[i][j] = 1; }
                else{   lenOfSeq[i][j] = lenOfSeq[i][j-1]+1; }
            }
        }

        ans = 0;

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                nm = lenOfSeq[i][j];
                number = a[i][j];
                for(int k=i; k>=1; k--){
                    if(a[k][j]!=number){    break;  }
                    nm = min(nm, lenOfSeq[k][j]);
                    ans+=nm;
                }
            }
        }

        cout<<"Case "<<t<<": "<<ans<<"\n";
    
    }

    return 0;
}