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

    ll T, n,p,k, kount, maximus;
    int *a;

    cin>>T;
    while(T--){
        cin>>n>>p>>k;
        a = new int[n+1];
        for(int i=0; i<n; i++){    cin>>a[i];   }
        sort(a,a+n);

        maximus = INT_MIN;
        int i=1;
        bool b = true;
        
        for(int i=0; i<n; i++){
            kount = 0;
            if(a[i]<=p){
                kount++; 
                p-=a[i];
                // r-l+1 = len = k, r = i, l = i-k+1
                int j = i-k+1;
                if(j<0){}
            }
        }


        
        delete[] a;
    }

    return 0;
}

