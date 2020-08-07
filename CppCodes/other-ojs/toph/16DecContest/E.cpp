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

    ll T, N, X, Y;
    ll P, K;
    ll  Q;
    ll B;
    string s;
    ll *a;
    cin>>T;
    while(T--){
        cin>>N>>X>>Y;
        cin>>P>>K;
        a = new ll[N+1];
        for(int i=0; i<=N; i++){ a[i] = 0;   }
        for(int i=0; i<N; i++){
            for(int j=0; j<X; j++){
                cin>>s;
                for(int k=0; k<Y; k++){
                    if(s[i]!='.'){
                        a[i]++;
                    }
                }
            }
        }

        for(int i=0; i<N; i++){
            a[i] = a[i]*K + P;
        }
        // sort
        sort(a,a+N);
        // cf
        for(int i=1; i<N; i++){
            a[i] = a[i]+a[i-1];
        }

        cin>>Q;
        while(Q--){
            cin>>B;
            int lb = lower_bound(a,a+N,B)-a;
            //if( a[lb]==B){    lb++;   }
            int kount = 0;
            for(int i=0; i<=lb; i++){
                if(a[i]<=B){    kount++;    }
            }
            //cout<<lb<<" A[i], B "<<a[lb]<<" "<<B<<"\n";
            cout<<kount<<"\n";
        }

        delete[] a;
    }

    return 0;
}

