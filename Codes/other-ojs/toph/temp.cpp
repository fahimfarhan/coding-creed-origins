#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back

#define ri(n) scanf("%d",&n)
#define rl(n) scanf("%lld",&n)

#define MX 101

#define BIGMAX 4*MX

#define MOD 1000000007


typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
//find_by_order(k) --> returns iterator to the kth largest element counting from 0
//order_of_key(val) --> returns the number of items in a set that are strictly smaller than our item

int setBit(int n,int p)
{
    return n|(1<<p);
}
bool checkBit(int n,int p)
{
    return (bool)(n&(1<<p));
}
int fx[]= {0,-1,0,1};
int fy[]= {1,0,-1,0};


ll bigMod(ll x,ll n)
{
    if(n==0)
        return 1;
    ll t = bigMod(x,n/2);
    t = ((t%MOD)*(t%MOD))%MOD;
    if(n%2)
    {
        t = ((x%MOD)*(t%MOD))%MOD;
    }
    return t;
}
struct info
{
    int u,v,w;
    info()
    {
        u = v = w = 0;
    }

    bool operator<(const info &rhs)

    {

    }

};

//***********************************************************************//
string a,b,c;
int dp[MX][MX][MX],mark[MX][MX][MX],marker;

int f(int i,int j,int k)
{
    if(i>=a.size() || j>=b.size())
    {
        if(k>=c.size())
            return 0;
        else
            return -1000;
    }

    if(mark[i][j][k] == marker)
    {
        return dp[i][j][k];
    }

    int mx = -10000000;

    if(k<c.size())
    {

        if(a[i] == b[j])
        {
            if(k == 0)
            {
                if(a[i] == c[k])
                {
                    mx = 1+f(i+1,j+1,k+1);
                    //cout<<"HI "<<mx<<endl;
                }
                mx = max(mx,1+f(i+1,j+1,k));
               // cout<<"baal "<<mx<<" "<<i<<" "<<j<<" "<<k<<endl;
            }
            else
            {
                if(a[i] == c[k])
                {
                    mx = 1+f(i+1,j+1,k+1);
                }
                else
                {
                    mx = f(i+1,j+1,k);
                }

            }
        }
        else
        {
            mx = f(i,j+1,k);
            mx = max(mx,f(i+1,j,k));
        }
    }
    else
    {
        if(a[i] == b[j])
        {
            mx = 1+f(i+1,j+1,k);
        }
        else
        {
            mx = f(i+1,j,k);
            mx = max(mx,f(i,j+1,k));
        }
    }

    mark[i][j][k] = marker;

    return dp[i][j][k] = mx;

}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;
    for(int tc = 1;tc<=t;tc++)
    {
        cin>>a>>b>>c;
        marker++;
        cout<<"Case "<<tc<<": "<<max(0,f(0,0,0))<<'\n';
    }


    return 0;



}

/*
1
akjgapksdpbokdf
jsjodfjipabdok
abd

*/