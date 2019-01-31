#include <bits/stdc++.h>

using namespace std;

#define N 105
int *a,*t,*p;

void build(int node, int lo, int hi){
    if(lo==hi){ t[node] = a[lo]; return;}
    if(lo>hi){  return; }

    int mid = (lo+hi)>>1;
    int left = node<<1;
    int right = left|1;

    build(left, lo, mid);
    build(right, mid+1, hi);

    t[node] = t[left]+t[right];

}

void propagate(int node, int L, int R){
    if(L>R){    return; }
        
    int temp = p[node];
    int left = node<<1;
    int right = left|1;

    p[left]+=temp;
    p[right]+=temp;

    p[node] = 0;
    
}

void update(int node, int L, int R, int l, int r, int u){
    if(L>R){    return ; }
    if(r<L || R<l){ return; }

    if(l<L && R<r){
        p[node] += u;
        return; 
    }
    if(p[node]!=0){ propagate(node, L,R);}
    int mid , left, right;
    mid = (L+R)>>1;
    left = node<<1;
    right = left|1;

    update(left, L,mid, l,r);
    update(right, mid+1, R, l, r);

    p[node] = p[left]+p[right];

}

int query(int node, int L, int R, int l, int r){
    if(L>R){    return ; }
    if(r<L || R<l){ return p[node]; }

    if(p[node]!=0){ propagate(node, L, R);}
    int mid = (L+R)>>1;

    int mid , left, right;
    mid = (L+R)>>1;
    left = node<<1;
    right = left|1;

    int q1 = query(left, L,mid, l,r);
    int q2 = query(right, mid+1, R, l, r);

    return q1+q2;
}

int main()
{
    a = new int[N];
    t = new int[4*N];
    p = new int[4*N];

    for(int i=01; i<=N; i++){
        a[i] = i;
    }

    build(1,1,N);

    for(int i=0; i<=N; i++){
        cout<<a[i]<<" ";
    }
    
    for(int i=0; i<=4*N; i++){
        cout<<t[i]<<" ";
    }
    
    for(int i=0; i<=4*N; i++){
        cout<<p[i]<<" ";
    }



    if(!a){ delete[] a; }
    if(!t){ delete[] t; }
    if(!p){ delete[] p; }
    return 0;
}
