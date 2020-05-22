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

    ll T, sum, maximus, temp, pos, s, n, *a;
    cin>>T;
    while(T--){
        cin>>n>>s;
        a = new ll[n+1];
        sum = 0;
        for(int i=0; i<n; i++){
            cin>>a[i]; sum += a[i];
        }
        if(sum <= s){    cout<<0<<"\n";  }
        else{
            maximus = -1;
            pos = 0;
            for(int i=0; i<n; i++){
                temp = sum - a[i];
                if( (temp > maximus) && (temp <= s)){
                    maximus = temp;
                    pos = i;
                }
            }
            pos++;
            cout<<pos<<"\n";

        }

        delete[] a;
    }

    return 0;
}

