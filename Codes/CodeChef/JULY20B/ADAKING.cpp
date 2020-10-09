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
#include <algorithm>
// #include <functional>
#include <iomanip>      // std::setprecision


using namespace std;

#define PI 2*acos(0)

//typedef long long int ll;
 #define ll long long int
// other popular ones=> int64_t, uint64_t => use for 10^18
ll MOD = 1e9+7;

// int n,m;

bool *isvisited;

#define N 10

int T, K;

char g[N][N];

int x1[] = {1,-1, 0, 0};
int _y1[] = {0, 0, 1,-1};

int x2[] = {-1, 0, 1};
int y2[] = {-1, 0, 1};

void placeObstacles(int x,int y) {
    int a,b;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            a = x + x2[i];
            b = y + y2[j];
            if(g[a][b] == '.') {
                g[a][b] = 'X';
            }
        }
    }
}

void initChessBoard(bool resetAll=true) {
    if(resetAll) {
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                g[i][j] = '.';
            }
        }
    }
    else{
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                if(g[i][j] == 'O') { g[i][j] = '.'; }
            }
        }
    }
    g[1][1] = 'O';
}

bool isSafe(int i, int j) {
    return ( (1<=i) && (i<=8) && (1<=j) && (j<=8) && (g[i][j] =='.') );
}

void dfsVisit(int ux, int uy) {
    if(K == 0) {    return; }
    g[ux][uy] = 'O';

    int vx, vy;
    K--;

    for(int i=0; i<4; i++) {
        if(K == 0) {    break;  }
        vx = ux + x1[i];
        vy = uy + _y1[i];

        if(isSafe(vx, vy)) {
            dfsVisit(vx, vy);
        }
    }

    placeObstacles(ux, uy);
}

void printer() {
    for(int i=1; i<=8; i++) {
        for(int j=1; j<=8; j++) {
            cout<<g[i][j];
        }cout<<"\n";
    }cout<<"\n";
    
    // for(int i=0; i<N; i++) {
    //     for(int j=0; j<N; j++) {
    //         cout<<g[i][j];
    //     }cout<<"\n";
    // }cout<<"\n";
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
        cin>>K;
        initChessBoard();
        dfsVisit(1,1);
        placeObstacles(1,1);    // cz it is not covered in the dfs...
        initChessBoard(false);
        printer();
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