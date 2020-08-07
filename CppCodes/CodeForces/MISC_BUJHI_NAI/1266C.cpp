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
ll MODULO = 1e9+7;

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


// int n,m;s
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

    int r, c;
    ll Aij = 0;
    cin>>r>>c;

    if( (r == 1) && (c == 1) ){
        cout<<0<<"\n";
    }else if(r == 1){
        for(int i=2; i<=c+1; i++){
            cout<<i<<" ";
        }cout<<"\n";
    }else if(c == 1){
        for(int i=2; i<=r+1; i++){
            cout<<i<<"\n";
        }
    }
    else{
        for(int i=1; i<=r; i++){
            for(int j=1; j<=c; j++){
                Aij = i*(j+r);
                cout<<Aij<<" ";
            }cout<<"\n";
        }
    }


    return 0;
}

