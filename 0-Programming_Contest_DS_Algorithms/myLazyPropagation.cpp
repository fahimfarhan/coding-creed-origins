#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

#define ll long long int

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);

void build(int pos, int L, int R);
void build();
void update();
int query(int pos, int L, int R, int ql, int qr);
int query(int ql, int qr);

void printer();


int *st, *a, n,N,  treesize=0;
double mypow;
vector<int> *g;
bool *isvisited;

int debugcount=0;


void build(){
    for(int i=01; i<=n; i++){
     //   cin>>a[i];
        st[i-1+N]=a[i];
    }

    int left, right;
    for(int i=N-1; i>=1; i--){
        left = i<<1; right = left|1;
        st[i] = st[left]+st[right];
    }
}

void build(int pos, int L, int R){
    if(L==R){
        // [1:1], [2:2], ... , [16:16] those base cases. so i == L
        st[pos] = a[L];
    }
    if(pos>N){  
        // I was getting some crazy errors! so it looks like this! Don't ask from past me to future me!
        //debugcount++; //cout<<debugcount<<" pos > N!\n"; 
        return; 
    }
    int mid, left, right;

    mid = (L+R)>>1;
    left = pos<<1;
    right = left|1;
    build(left, L,mid);
    build(right, mid+1, R);
    st[pos] = st[left]+st[right];
}

int query(int pos, int L, int R, int ql, int qr){
    if(qr<L || R<ql){   return 0;   } // case 1: out of range -_-
    // case2: a perfect match
    if( (ql<=L) && (qr >= R) ){ 
        return st[pos];
    }
    int left, right, mid;
    left = pos<<1;
    right = left|1;
    mid = (L+R)>>1;
    int x,y;
    x = query(left, L, mid, ql, qr);
    y = query(right, mid+1, R, ql, qr);

    return (x+y);

}

int query(int ql, int qr){
    return query(1,1,N,ql,qr);
}

void printer(){
    for(int i=1; i<treesize; i++){
        cout<<st[i]<<" ";
    }cout<<"\n";
}


int main(int argc, char const *argv[])
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;

    mypow = log2(n);
    mypow = ceil(mypow);
    treesize = 1<<((int)mypow+1);
    cout<<treesize<<"\n";
    // treesize ok
    st = new int[treesize+1];
    // a = new int[n+1]; // WRONG! YOU'LL GET ARRAY OUT OF BOUND EXCEPTION!
    
    N = treesize/2;
    cout<<"N="<<N<<"\n";
    a = new int[N+1];
    
    for(int i=0; i<N; i++){
        a[i]=0;
    }
    for(int i=01; i<=n; i++){
        cin>>a[i];
        // st[i-1+treesize/2]=a[i];
    }

    for(int i=01; i<=n; i++){
        cout<<a[i]<<" ";
        // st[i-1+treesize/2]=a[i];
    }cout<<"\n";


    //build(1,1,N);
    build();
    printer();

    cout<<query(7,15)<<"\n";
    cout<<query(1,5)<<"\n";
    cout<<query(3,7)<<"\n";
    cout<<query(2,11)<<"\n";
    
    // st has 3 functions: build , query, update 
    // but we focus on build and query as update will be changed in lazy propagation.
    // just for practice, we are writing update. NEVER use in production


    if(!a)delete[] a;
    if(!st)delete[] st;
    return 0;
}
