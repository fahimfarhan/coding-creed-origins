#ifdef _WIN32

#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>

#else

#include <bits/stdc++.h>

#endif

using namespace std;

#define PI 2*acos(0)

typedef long long int ll;
// #define ll long long int
// other popular ones=> int64_t, uint64_t => use for 10^18
ll MODULO = 1e9+7;

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


// int n,m;s
vector<int> *g;
bool *isvisited;

ll T, N, a,b,*A, *B;
int64_t R;

double rec(int l, int r){
    if(l>r){    return 0; }
    double ret;
    if(l == r){
        ret = 1.0*(A[l]+B[r])/2;
        return ret;
    }

    int mid = (l+r)>>1;

    ret = rec(l,mid)+rec(mid+1,r);
    ret = ret/2;
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

    cin>>T;
    while(T--){
        cin>>N;
        A = new ll[N+1]; B = new ll[N+1];
        R = 0;
        for(int i=0; i<N; i++){ cin>>A[i];   }
        for(int i=0; i<N; i++){ cin>>B[i];   }
        sort(A,A+N); sort(B,B+N);

        for(int i=0; i<N; i++){
            a = A[i]+B[i];
            a=a>>1;
            R+=a;
        }
        
        //R = R/2;
        // R = rec(0,N-1);
        

        cout<<R<<"\n";


        //delete[] A; delete[] B;
    }

    return 0;
}
