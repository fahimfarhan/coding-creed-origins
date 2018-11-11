#include <bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d",&x)
#define sf(x) scanf("%f",&x)

#define pi(x) printf("%d\n",x)
#define pf(x) printf("%.4f\n",x)

#define ll long long int

#define sll(x) scanf("%I64d",&x);
#define pll(x) printf("%-I64d\n",x);
map<int, int> mp;
int *tree, *A;
bool *btree;
int n,m,l;

void build(int node, int lo, int hi){
    if(lo == hi){   btree[node] = A[lo]>l?true:false; }
    int mid = (lo+hi)/2;
    int left = node<<1;
    int right = left|1;
    build(left, lo, mid);
    build(right, mid+1,hi);
}
void update(int node, int lo, int hi, int i){
    if(i<lo || i>hi){   return; }
    if(lo == hi){
            if(lo == i){ btree[node] = A[lo]>l?true:false;  }
            return; 
       }
    int mid = (lo+hi)/2;
    int left = node<<1;
    int right = left|1;

    update(left , lo,   mid, i);
    update(right, mid+1, hi, i);

    btree[node] = btree[left]&btree[right];
}

int query(int node,int lo,int hi,int i,int j){
    int ret = 0;
    if(lo>hi){  return 0; }
    else if(lo>j || hi<i) return 0;
    if(lo>=i && hi <= j){ 
        if(tree[node]) return 1;
        else return 0;
    } 
    int mid=(lo+hi)/2;
    int p1=query(node*2,lo,mid,i,j);
    int p2=query(node*2+1,mid+1,hi,i,j);
    ret = p1+p2;
    return ret;
}


int main(int argc, char const *argv[])
{
	/* code */
  /* Soln soln */
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

	//int n;
    cin>>n>>m>>l;
    A = new int[n+1];
    tree = new int[4*n];
    btree = new bool[4*n];

    for(int i=1; i<=n; i++){
        cin>>A[i];
    }

    build(1, 1,n);
    while(m--){
        int q = -1;
        cin>>q;
        if(q==0){
            cout<<query(1,1,n,1,n)<<"\n";
        }else if(q==1){
            int pi, di;
            cin>>pi>>di;
            A[pi]+=di;
            update(1,1,n,pi);
        }
    }


    delete[] A;
    delete[] tree;
    delete[] btree;
	return 0;
}
