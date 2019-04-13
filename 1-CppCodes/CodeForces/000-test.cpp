#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <memory.h>
#include <ctime>
 
using namespace std;
 
#define ABS(a) ((a>0)?a:-(a))
#define MIN(a,b) ((a<b)?(a):(b))
#define MAX(a,b) ((a<b)?(b):(a))
#define FOR(i,a,n) for (int i=(a);i<(n);++i)
#define FI(i,n) for (int i=0; i<(n); ++i)
#define pnt pair <int, int>
#define mp make_pair
#define PI 3.14159265358979
#define MEMS(a,b) memset(a,b,sizeof(a))
#define LL long long
#define U unsigned
 
int a[200100];
int val[200100];
int b[200100];
int main()
{
        int n,q;
        scanf("%d%d",&n,&q);
        FOR(i,0,n)
                scanf("%d",&a[i]);
        sort(a,a+n);
        FOR(i,0,q)
        {
                int l,r;
                scanf("%d%d",&l,&r);
                l--;
                r--;
                val[l]++;
                if (r<n-1)
                        val[r+1]--;
        }
        int v=0;
        FOR(i,0,n)
        {
                v+=val[i];
                b[i]=v;
        }
        sort(b,b+n);
        LL res=0;
        FOR(i,0,n)
                res+=(b[i]*1ll*a[i]);
        cout<<res<<endl;
    return 0;
}