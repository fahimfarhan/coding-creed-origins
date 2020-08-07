/* Author : Qazi Fahim Farhan (@fahimfarhan) */
/* May the CodeForces be with you! */

#include <iostream>
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
vector<int> *g;
bool *isvisited;

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

    ll T, N, k, r, c;
    ll M[105][105];

    cin>>T;
    for(int t=1; t<=T; t++){
        cin>>N;

        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++){
                cin>>M[i][j];
            }
        }

        k = 0; r=0; c=0;
        for(int i=0; i<N; i++){
            k+=M[i][i];
        }

        // check rows
        // for(int i=1; i<N; i++){
        //     ll hare, tortoise;
        //     hare = M[i][0];
        //     tortoise = M[i][0];
        //     bool duplicateElementExists = false;
        //     while(true){
        //         if( (hare > N) || (tortoise > N) ){  break; }
        //         hare = M[i][hare]; 
        //         tortoise=M[i][tortoise]; 
        //         tortoise=M[i][tortoise];
                
        //         if(hare == tortoise){
        //             duplicateElementExists = true; 
        //             break;
        //         }
        //     }

        //     if(duplicateElementExists){ r++; }
        // }

        // check cols
        // for(int i=0; i<N; i++){
        //     ll hare, tortoise;
        //     hare = M[0][i];
        //     tortoise = M[0][i];
        //     bool duplicateElementExists = false;
        //     while(true){
        //         if( (hare > N) || (tortoise > N) ){  break; }
        //         hare = M[hare][i]; 
        //         tortoise=M[tortoise][i]; 
        //         tortoise=M[tortoise][i];
                
        //         if(hare == tortoise){
        //             duplicateElementExists = true; 
        //             break;
        //         }
        //     }

        //     if(duplicateElementExists){ c++; }
        // }

        // rows
        r = 0;
        for(int i=0; i<N; i++){
            bool isVisited[N+5] = {0};
            for(int j=0; j<N; j++){
                int temp = M[i][j];
                if(isVisited[temp]){    r++; break; }
                else{   isVisited[temp] = 1; }
            }
        }

        // columns
        c = 0;
        for(int i=0; i<N; i++){
            bool isVisited[N+5] = {0};
            for(int j=0; j<N; j++){
                int temp = M[j][i];
                if(isVisited[temp]){    c++; break; }
                else{   isVisited[temp] = 1; }
            }
        }

        cout<<"Case #"<<t<<": "<<k<<" "<<r<<" "<<c<<"\n";
    }


    return 0;
}

