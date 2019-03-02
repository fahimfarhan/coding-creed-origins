#include<bits/stdc++.h>

using namespace std;

const int N = 1e5;
int n;
int t[2*N];

int h = sizeof(int) * 8 - __builtin_clz(n);
int d[N];

void apply(int p, int value){
    t[p]+=value;
    if(p<n){    d[p]+=value;    }
}

void build(int p){
    while(p>1){
        p = p>>1;
        t[p] = max(t[p<<1],t[p<<1|1] + d[p] );
    }
}

void push(int p){
    for(int j=h; j>0; --j){
        int i=p>>j;
        if(d[i] != 0){
            apply(i<<1, d[i]);
            apply(i<<1|1, d[i]);
            d[i]=0;
        }
    }
}

void increment(int l, int r, int value){
    l+=n; r+=n;
    int l0=l, r0=r;

    while(l<r){
        if(l&1){    apply(l++, value);  }
        if(r&1){    apply(--r, value);    }
    }
    build(l0);
    build(r0-1);
}

int query(int l, int r){
    int ret = INT_MIN;
    l+=n; r+=n;
    push(l);
    push(r-1);

    while(l<r){
        if(l&1){    ret = max(ret, t[l++]);   }
        if(r&1){    ret = max(t[--r],ret);  }
        l = l>>1;
        r = r>>1;
    }
    return ret;
}

// assignment modifications, sum query
void calc(int p, int k){
    if(d[p] == 0) { t[p] = t[p<<1] + t[p<<1|1]; }
    else{   t[p] = d[p]*k;  }
}

void apply(int p, int value, int k){
    t[p] = value*k;
    if(p < n){  d[p] = value;   }
}

void build(int l, int r){
    int k=2;
    l+=n; r+=n;
    while(l>1){
        l=l>>1; r=r>>1;
        for(int i=r; i>=l; --i){calc(i,k);}
        k=k<<1;
    }
}

void push(int l, int r){
    int s=h, k=1<<(h-1);
    
    l=l+n; r+=n;
    while(s>0){
        for(int i=l>>s; i<=r>>s; ++i ){
            if(d[i]!=0){
                apply(i<<1, d[i], k);
                apply(i<<1|1, d[i],k);
                d[i]=0;
            }
        }
        --s; k=k>>1;
    }
}

int main()
{

    return 0;
}