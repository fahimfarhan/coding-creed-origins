#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define             f(i,n)         	for(int i=0;i<n;i++)
#define             f1(i,n)        	for(int i=1;i<=n;i++)
#define             fab(i,a,b)     	for(int i=a;i<=b;i++)
#define             ll             	long long int
#define             pb             	push_back
#define             te(t)          	int t;cin>>t;while(t--)
#define             MOD            	1e9+7
#define             fast           	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define             MEM(a,b)       	memset(a,b,sizeof(a))
#define             MP            	make_pair
#define             all(v)         	v.begin(),v.end()
#define             mnv(v)         	*min_element(v.begin(),v.end())
#define             mxv(v)         	*max_element(v.begin(),v.end())
#define             toint(a)            atoi(a.c_str())
#define             valid(tx,ty)   	(tx>=0&&tx<n&&ty>=0&&ty<m)
#define             issq(x)        	(((ll)(sqrt((x))))*((ll)(sqrt((x))))==(x))
#define             ub             	upper_bound
#define             lb             	lower_bound
#define             grtsrt(v)      	sort(v.begin(),v.end(),greater<ll>())
#define             Unique(v)      	v.erase(unique(all(v)),v.end())
#define             ff             	first
#define             ss             	second
#define             sff(a,b)       	scanf("%d %d",&a,&b)
#define             sfff(a,b,c)    	scanf("%d %d %d",&a,&b,&c)
#define		    NL		        pf("\n");
#define             DBG                 pf("ALSMK\n");

#define             ull            	unsigned long long
#define             ld             	long double
#define             pii            	pair<int,int>
#define             pll            	pair<ll,ll>
#define             vi             	vector<int>
#define             vll            	vector<ll>
#define             vc             	vector<char>
#define             vs             	vector<string>
#define             vpll           	vector<pll>
#define             vpii           	vector<pii>
#define             umap           	unordered_map
#define             uset           	unordered_set
#define             PQ             	priority_queue
#define             nl             	"\n"
#define             lg(r,n)        	(int)(log2(n)/log2(r))
#define             sz(s)               (int)s.size()
#define             M              	1000000



#define pf                          printf
#define sf(a)                       scanf("%d",&a)
#define sfl(a)                      scanf("%lld",&a)
#define sff(a,b)                    scanf("%d %d",&a,&b)
#define sffl(a,b)                   scanf("%lld %lld",&a,&b)
#define sfff(a,b,c)                 scanf("%d %d %d",&a,&b,&c)
#define sfffl(a,b,c)                scanf("%lld %lld %lld",&a,&b,&c)
#define sffff(a,b,c,d)              scanf("%d %d %d %d",&a,&b,&c,&d)
#define sffffl(a,b,c,d)             scanf("%lld %lld %lld %lld",&a,&b,&c,&d)
#define sfffff(a,b,c,d,e)           scanf("%d %d %d %d %d",&a,&b,&c,&d,&e)
#define sfffffl(a,b,c,d,e)          scanf("%lld %lld %lld %lld %lld",&a,&b,&c,&d,&e)
string tostr(int n) {stringstream rr;rr<<n;return rr.str();}
template<class T, class T2> inline int chkmax(T &x, const T2 &y) { return x < y ? x = y, 1 : 0; }
template<class T, class T2> inline int chkmin(T &x, const T2 &y) { return x > y ? x = y, 1 : 0; }


bool Chk(int N,int pos){return (bool)(N & (1<<pos));}
int Set(int N,int pos){	return N=N | (1<<pos);}
int reset(int N,int pos){return N= N & ~(1<<pos);}




//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move

const int N=5001;
int a[N];
int dp[N][N];
int main()
{
        int t;sf(t);
        int ca=0;
        while(t--)
        {
                int n,k;
                sff(n,k);
                for(int i=0;i<=k;i++){
                    dp[0][i]=0;
                }
                for(int i=1;i<=n;i++){
                    sf(a[i]);

                }
                int ans=-INT_MAX;
                for(int i=1;i<=n;i++){

                    for(int j=0;j<=k;j++){
                        int x=0;int y=0;
                        x=max(dp[i-1][j]+a[i],a[i]);
                        if(a[i]<0&&j>0){
                            y=dp[i-1][j-1];
                            y=max(x,y);
                            dp[i][j]=max(x,y);
                        }else dp[i][j]=x;
                        //
                    }
                    chkmax(ans,dp[i][k]);
                }
                pf("Case %d: %d",++ca,ans);
                puts("");
        }
}