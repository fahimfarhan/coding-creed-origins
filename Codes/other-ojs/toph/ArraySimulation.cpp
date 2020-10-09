#include <bits/stdc++.h>
using namespace std;
#define MAX 200005
#define ll long long int
#define Left (node*2)
#define Right (node*2+1)
#define mid ((lo+hi)/2)
#define MOD 100000007

//lazy propagation
ll a[MAX*5];
ll m[MAX*5];
ll d[MAX*5];
ll s[MAX*5];
ll tree[MAX*5];

ll Sum(ll l)        {return (l*(l+1)) /2;}
ll Range(ll l,ll r) {return (Sum(r)-Sum(l-1))%MOD;}
ll Mul(ll a,ll b)   {return (a*b)%MOD;}
ll Add(ll a,ll b)   {return (a+b)%MOD;}
ll Sub(ll a,ll b)   {return ((a-b)%MOD+MOD)%MOD;}

void lazyPropagation(int node,int lo,int hi){
    ll Count = hi- lo +1;
    if(s[node]) tree[node] = Mul(s[node], Count);
    tree[node] = Mul(tree[node],m[node]);
    tree[node] = Add(tree[node],Mul(a[node], Count));
    tree[node] = Add(tree[node],Mul(d[node], Range(lo,hi)));

    if(lo != hi) {
        if(s[node]){
            s[Left] = s[Right] = s[node];
            m[Left] = m[Right] = 1;
            a[Left] = a[Right] = d[Left] = d[Right] = 0;
        }

        m[Left] = Mul(m[Left],m[node]); m[Right] = Mul(m[Right],m[node]);
        a[Left] = Mul(a[Left],m[node]); a[Right] = Mul(a[Right],m[node]);
        d[Left] = Mul(d[Left],m[node]); d[Right] = Mul(d[Right],m[node]);

        a[Left] = Add(a[Left],a[node]); a[Right] = Add(a[Right],a[node]);
        d[Left] = Add(d[Left],d[node]); d[Right] = Add(d[Right],d[node]);
    }
    m[node] = 1; a[node] = d[node] = s[node] = 0;
}

void updateRange(int node, int lo, int hi, int i, int j, ll upd1, ll upd2, int Type){
    lazyPropagation(node,lo,hi);

    if(lo>hi) return;
    else if(lo>j || hi<i) return;
    if(lo>=i && hi<=j){
        if(Type == 1) a[node] = upd1, d[node] = upd2;
        else if(Type == 2) m[node] = upd1;
        else if(Type == 3) s[node] = upd1;

        lazyPropagation(node,lo,hi);
        return;
    }

    updateRange(Left,lo,mid,i,j,upd1, upd2, Type);
    updateRange(Right,mid+1,hi,i,j, upd1, upd2, Type);
    tree[node]=Add(tree[Left],tree[Right]);
}

ll queryRange(int node,int lo,int hi,int i,int j){
    lazyPropagation(node,lo,hi);
    if(lo>hi) return 0;
    else if(lo>j || hi<i) return 0;
    if(lo>=i && hi <= j) return tree[node];
    ll p1=queryRange(Left,lo,mid,i,j);
    ll p2=queryRange(Right,mid+1,hi,i,j);
    ll ss = Add(p1,p2);
    if(ss < 0) ss += MOD;
    return ss;
}

int main(){
    int t;
    scanf("%d",&t);

    for(int cs=1;cs<=t;cs++){
        for(int i=0;i<MAX*5;i++) m[i] = 1, a[i] = d[i] = s[i] = tree[i] = 0;

        int n,m;
        scanf("%d %d",&n,&m);

        printf("Case %d:\n",cs);
        for(int i=1;i<=m;i++){
            int tp,l,r;
            ll upd1,upd2;
            scanf("%d",&tp);

            if(tp == 1) scanf("%d %d %lld %lld",&l,&r,&upd1,&upd2), updateRange(1,1,n,l,r,Sub(upd1,upd2*l),upd2,1);
            else if(tp==2) scanf("%d %d %lld",&l,&r,&upd1), updateRange(1,1,n,l,r,upd1,0,2);
            else if(tp==3) scanf("%d %d %lld",&l,&r,&upd1), updateRange(1,1,n,l,r,upd1,0,3);
            else scanf("%d %d",&l,&r), printf("%lld\n",queryRange(1,1,n,l,r));
        }
    }
}