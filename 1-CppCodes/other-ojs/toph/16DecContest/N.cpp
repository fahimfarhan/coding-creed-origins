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

int add(int x, int y){
    int ret = 0;
    ret = x+y;
    if(ret>MODULO){
        ret = ret - MODULO;
    }
    return ret;
}

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

    int T;
    int MAX_SIZE = 1000001;
    int N, a[MAX_SIZE];
    N = MODULO;
    // preprocessing
    a[0] = 1, a[1] = 1;
    for(int i=2; i<MAX_SIZE; i++){
        a[i] = add(a[i-1], a[i-2]);
    }
    // solve
    cin>>T;
    while(T--){
        cin>>N;
        cout<<a[N-1]<<"\n";
    }


    return 0;
}

