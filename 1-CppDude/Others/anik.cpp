#include<bits/stdc++.h>
using namespace std;

#define MAX 400005
#define MAXN 1000005
#define ll long long int

ll A[MAX];
ll Div[MAXN];
ll tree[MAX*3];

void build(int node, int lo, int hi){
    if (lo==hi) {tree[node]=A[lo]; return;}
    int Left=node*2;
    int Right=node*2+1;
    int mid=(lo+hi)/2;
    build(Left,lo,mid);
    build(Right,mid+1,hi);
    tree[node]=tree[Left]+tree[Right];
}

void update(int node, int lo, int hi, int i){
    if (i>hi || i<lo) return;
    if (lo==hi)  {tree[node]=Div[tree[node]]; return;}
    int Left=node*2;
    int Right=node*2+1;
    int mid=(lo+hi)/2;
    update(Left,lo,mid,i);
    update(Right,mid+1,hi,i);
    tree[node]=tree[Left]+tree[Right];
}

ll queryRange(int node,int lo,int hi,int i,int j){
    if(lo>hi) return 0;
    else if(lo>j || hi<i) return 0;

    if(lo>=i && hi <= j) return tree[node];
    int mid=(lo+hi)/2;
    ll p1=queryRange(node*2,lo,mid,i,j);
    ll p2=queryRange(node*2+1,mid+1,hi,i,j);
    return p1+p2;
}

set<int>v;
set<int>:: iterator it1,it2;
vector<int>toRemove;

int main(){
    for(int i=1;i<MAXN;i++) for(int j=i;j<MAXN;j+=i) Div[j]++;

    int n,m;
    scanf("%d %d",&n,&m);

    for(int i=1;i<=n;i++) {scanf("%I64d",&A[i]); assert(A[i]<=1000000);}
    for(int i=1;i<=n;i++) {if(A[i]!=Div[A[i]]) v.insert(i);}

    build(1,1,n);
    for(int i=1;i<=m;i++){
        int cmd,l,r;
        scanf("%d %d %d",&cmd,&l,&r);
        if(cmd==1){
            it1=v.lower_bound(l);
            it2=v.upper_bound(r);

            while(it1!=it2){
                int now=*it1;
                update(1,1,n,now);
                A[now]=Div[A[now]];
                if(A[now]==Div[A[now]]) toRemove.push_back(now);
                it1++;
            }

            for(int x=0;x<toRemove.size();x++) v.erase(toRemove[x]);
            toRemove.clear();
        }
        else printf("%I64d\n",queryRange(1,1,n,l,r));
    }
}
