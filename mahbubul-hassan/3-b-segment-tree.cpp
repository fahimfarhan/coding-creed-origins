#include <bits/stdc++.h>

using namespace std;
const int N = 1e5;
int n;
int t[2*N];

/*
Non-commutative combiner functions

For now we considered only the simplest combiner function — addition. It is commutative, which means the order
 of operands doesn't matter, we have a + b = b + a. The same applies to min and max, so we can just change all
  occurrences of + to one of those functions and be fine. But don't forget to initialize query result to 
  infinity instead of 0.
*/
void build(){
    for(int i=n-1; i>0; i--){
        t[i] = t[i<<1]+t[i<<1|1];
    }
}

void modify(int p, int value){
    //for(t[p+=n] = value; p>1; p>>=1)
    //{   t[p>>1] = t[p]+t[p^1];  }
    p=p+n;
    while(p>1){
        t[p>>1] = t[p]+t[p^1];
        p=p>>1; 
    }
}

int query(int l,int r){
    int ret = 0;
    l=l+n; r=r+n;
    while(l<r){
        if(l&1){    ret = ret+t[l++];   }
        if(r&1){    ret = ret+t[--r];   }
        l = l>>1;
        r=r>>1;
    }
    return ret;
}

// modify on interval , single element access 
void modifyInterval(int l, int r, int value){
    l=l+n; r=r+n;
    while(l<r){

    }
}

int querySingle(int p){
    int ret = 0;
    p=p+n;
    while(p>0){
        ret = ret+t[p];
        p = p>>1;   // p=p/2;
    }
    return ret;
}

int push(){
    for(int i=1; i<n; i++){
        t[i<<1]+=t[i];
        t[i<<1|1]+=t[i];
        t[i] = 0;
    }
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){    cin>>t[n+i];    }
    
    build();
    modify(0,1);
    cout<<query(3,11)<<"\n";
    return 0;
}