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

    ll T, N, B, *A;
    int kount=0;
    cin>>T;
    for(int t=1; t<=T; t++){
        cin>>N>>B;
        A = new ll[N+1];
        for(int i=0; i<N; i++){
            cin>>A[i];
        }

        sort(A,A+N);

        kount = 0;
        for(int i=0; i<N; i++){
            if(A[i]<=B){
                kount++;
                B-=A[i];
            }else{
                break;
            }
        }
        cout<<"Case #"<<t<<": "<<kount<<"\n";

        delete[] A;
    }


    return 0;
}

