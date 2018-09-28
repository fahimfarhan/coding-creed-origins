#include <bits/stdc++.h>
using namespace std;

#define MAX 400005
#define MAXN 1000005
#define ll long long int

ll A[MAX];
ll Div[MAXN];
ll tree[MAX*4];

void build(int node, int lo, int hi){
    if(lo == hi){   tree[node] = A[lo]; return; }
    int left = node<<1;
    int right = node<<1|1;

    int mid = (lo+hi)>>1;

    build(left,lo,mid);
    build(right,mid+1, hi);
    tree[node] = tree[left]+tree[right];

}

void update(int node, int lo, int hi, int i){
    if(i>hi || i<lo){   return; }
    if(lo==hi){ tree[node] =  Div[tree[node]]; return;  }
    int left = node<<1;
    int right = node<<1|1;

    int mid=(lo+hi)>>1;
    update(left, lo,mid,i);
    update(right, mid+1, right, i);

    tree[node] = tree[left]+tree[right];
}

ll queryRange(int node, int lo, int hi, int i, int j){
    if(lo>hi){  return 0; }
    else if(lo>j || hi<i){  return 0;   }

    if(lo >= i && hi <= j){ return tree[node];  }
    int mid = (lo+hi)>>1;
    int left = node<<1;
    int right = node<<1|1;
    ll p1 = queryRange(left, lo,mid,i,j);
    ll p2 = queryRange(right, mid+1,hi,i,j);
    return p1+p2;
}

set<int> v;
set<int>::iterator it1,it2;
vector<int> toRemove;

int main()
{
    for(int i=1; i<MAXN; i++){  for(int j=i; j<MAXN; j+=i) Div[j]++; }

    int n,q;
    cin>>n>>q;

    for(int i=1; i<=n; i++){    cin>>A[i];  }
    for(int i=1; i<=n; i++){
        if(A[i] != Div[A[i]]){  v.insert(i);    }
    }

    build(1,1,n);
    while(q--){
        int cmd, l,r;
        cin>>cmd>>l>>r;
        if(cmd==1){
            it1 = v.lower_bound(l);
            it2 = v.upper_bound(r);
            while(it1!=it2){
                int now=*it1;
                update(1,1,n,now);
                A[now] = Div[A[now]];
                if(A[now]==Div[A[now]]){   toRemove.push_back(now);}
                it1++;
            }
            for(int j=0; j<toRemove.size();j++){    v.erase(toRemove[j]);}
            toRemove.clear();
        }else{
            ll ans123 = queryRange(1,1,n,l,r);
            cout<<ans123<<endl;
        }
    }

    return 0;
}