#include <set>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;
typedef pair<LL, LL> pLL;
typedef pair<LL, int> pLi;
typedef pair<int, LL> pil;;
typedef pair<int, int> pii;
typedef unsigned long long uLL;

#define lson rt<<1
#define rson rt<<1|1
#define lowbit(x) x&(-x)
#define name2str(name) (#name)
#define bug printf("*********\n")
#define debug(x) cout<<#x"=["<<x<<"]" <<endl
#define FIN freopen("D://code//in.txt","r",stdin)
#define IO ios::sync_with_stdio(false),cin.tie(0)

const double eps = 1e-8;
const int mod = 1000000007;
const int maxn = 2e5 + 7;
const double pi = acos(-1);
const int inf = 0x3f3f3f3f;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;

LL l, r;

int main(){
    scanf("%lld%lld", &l, &r);
    puts("YES");
    for(LL i = l; i <= r; i += 2) {
        printf("%lld %lld\n", i, i + 1);
    }
    return 0;
}