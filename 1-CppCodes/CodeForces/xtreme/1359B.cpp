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

    ll T;
    ll n,m,x,y, cost;
    string *a;

    cin>>T;
    while(T--) {
        cin>>n>>m>>x>>y;
        a = new string[n+1];
        for(int i=0; i<n; i++) {    cin>>a[i];  }

        cost = 0;
        if( (2*x) <= y) {
            // use all x 
            for(int i=0; i<n; i++) {
                for(int j=0; j<m; j++) {
                    if(a[i][j] == '.') {
                        cost+=x;
                    }
                }
            }
        }else{
            for(int i=0; i<n; i++) {
                for(int j=0; j<m; j++) {
                    if(a[i][j] == '.') {
                        if( (j+1) < m && a[i][j+1] == '.') {
                            cost += y;
                            a[i][j] = 'y'; a[i][j+1] = 'y';
                        }else{
                            cost+=x;
                            a[i][j] = 'x';
                        }
                    }
                }
            }
        }

        cout<<cost<<"\n";

        delete[] a;
    }


    return 0;
}

