/* Author : Qazi Fahim Farhan (@fahimfarhan) */
/* May the CodeForces be with you! */

#include <iostream>
#include <climits>  // this includes INT_MIN, INT_MAX, ... ...
// #include <sstream>
// #include <cstdio>
// #include <cmath>
// #include <cstring>
// #include <cctype>
// #include <string>
#include <vector>
// #include <list>
// #include <set>
// #include <map>
// #include <queue>
// #include <stack>
// #include <algorithm>
// #include <functional>
#include <iomanip>      // std::setprecision


using namespace std;

#define PI 2*acos(0)

//typedef long long int ll;
 #define ll long long int
// other popular ones=> int64_t, uint64_t => use for 10^18
ll MOD = 1e9+7;

// int n,m;
bool isvisited[60][60];

int T, n,m;
int goodKount, badKount;
bool isPossible;
string g[60];


bool isValid(const int& i,const int& j) {
    return ((i>=0) && (i<n) && (j>=0) && (j<m));
}

int dfs(const int& i,const int& j) {
    isvisited[i][j] = true;
    int ret = 0;
    if(g[i][j] == 'G') {
        ret = 1;
    }
    int x = i+1, y = j;
    if(isValid( x,y )){
        if( !isvisited[x][y] && g[x][y] != '#' ) {
            ret += dfs(x,y);
        }
    }
    x = i - 1; y = j;
    if(isValid( x,y )){
        if( !isvisited[x][y] && g[x][y] != '#' ) {
            ret += dfs(x,y);
        }
    }

    x = i; y = j+1;
    if(isValid( x,y )){
        if( !isvisited[x][y] && g[x][y] != '#' ) {
            ret += dfs(x,y);
        }
    }

    x = i; y = j-1;
    if(isValid( x,y )){
        if( !isvisited[x][y] && g[x][y] != '#' ) {
            ret += dfs(x,y);
        }
    }

    return ret;
}

int main(int argc, char const *argv[])
{
    /* code */
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    /*
    std::cout << std::fixed;
    std::cout << std::setprecision(10);
    cout << num1 << endl;
    */
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>T;
    while(T--) {
        cin>>n>>m;

        for(int i=0; i<=n; i++) {
            for(int j=0; j<=m; j++) {
                isvisited[i][j] = false;
            }
        }

        goodKount = 0; badKount = 0;

        for(int i=0; i<n; i++) {    cin>>g[i];  }
        isPossible = true;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(g[i][j] == 'G') {    goodKount++;    }
                else if(g[i][j] == 'B') {   
                    badKount++; 
                    if(i+1 <n) {
                        if(g[i+1][j] !='G'){    g[i+1][j] = '#';    }
                        else{   isPossible = false; }
                    }
                    if(i-1 >=0 ) {
                     if(g[i-1][j] !='G'){    g[i-1][j] = '#';    }
                        else{   isPossible = false; }   
                    }

                    if(j+1 < m) {
                        if(g[i][j+1] !='G'){    g[i][j+1] = '#';    }
                        else{   isPossible = false; }
                    }

                    if(j-1 >= 0 ) {
                        if(g[i][j-1] !='G'){    g[i][j-1] = '#';    }
                        else{   isPossible = false; }
                    }
                }
            }
        }
        // case 2: G-B are side by side
        if(!isPossible) {
            // cout<<"No\n";
            isPossible = false; 
        }else if(badKount==0 && g[n-1][m-1]!='#'){
            // cout<<"YES\n";
            isPossible = true;
        }else if(goodKount == 0 && g[n-1][m-1] != 'B') {
            isPossible = true;
        }else{
            // already wall given
            if(g[n-1][m-1] != '#') {
                // run dfs
                int x = n-1; int y = m-1;
                int dfsKount = dfs(x,y);
                if(dfsKount == goodKount) {
                    isPossible = true;
                }else{
                    isPossible = false;
                }
            }else{
                isPossible = false;
            }
        }

        if(isPossible) {    cout<<"Yes\n";  }
        else{   cout<<"No\n";   }

    

    }


    return 0;
}

/*
---------- Interactive problems ---------

    on each interactive questions' end, add `cout.flush()`
    say, cout<<"some weirdo question";
    cout<<"\n"; // end of question
    cout.flush(); // <-- just like this

    if still confusing, check out 1363D.cpp
    
*/