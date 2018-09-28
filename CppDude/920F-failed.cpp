#include <bits/stdc++.h>

using namespace std;


int *t,*lazy;
int n;

void build(){
    for(int i=n-1; i>0; i--)
        t[i] = t[i<<1]+t[i<<1|1];   // t(i) = t(2i)+t(2i+1)
}

void modify(int p, int value){
    /**
     * s1: update the leaf node
    */
   t[p+n] = value;
   for(int i=p+n; i>1; i=i>>1){
       t[i>>1] = t[i]+t[i^1];   // 1,2  3,4   
       // i|1 dile 2,3 3,3 4,5  erokom hoye jabe
       // i^1 deyay 2,1  1,2 erokom vabe asbe! :D
       // orthat order change holeo correct ans
   }

}

int query(int L, int R){
    int res = 0;
    int l,r;
    l=L; r=R;
    l=l+n; r=r+n;
    while(l<r){
        if(l&1){  res += t[l]; l++; }
        if( (r&1) ){  r--;  res += t[r];  }
        l >>= 1;
        r >>= 1; 
    }

    return res;
}

void lazy_propagate(int L, int R, int add_u){
    int l,r;
    l=n+L;
    r=n+R;
    while(l<r){
        if(l&1){    lazy[l]+=add_u; l++;    }
        if(!(r&1)){ lazy[r]+=add_u; r--;    }
        l = l>>1;
        r = r>>1;
    }
}

void lazy_update(){
    for(int i=1; i<=n; i++){
        lazy[i<<1]+=lazy[i];
        lazy[(i<<1)|1]+= lazy[i];
        lazy[i] = 0;
    }
    for(int i=1; i<=n; i++){
        t[i] = t[i] + lazy[i];
        lazy[i] = 0;
    }
}


class Divisor{
private:
    int n1; 
    
public:
vector<int> *divisor;
    Divisor(){
        // cin>>n;
        n1 = 1000000;
        divisor = new vector<int>[n1+1];

        for(int i=1; i<=n1; i++){
            for(int j=i; j<=n1; j+=i){
                divisor[j].push_back(i);
                //cout<<"divisor["<<j<<"].push_back("<<i<<"); \n";
            }
        }
    }
    ~Divisor(){if(!divisor)delete[] divisor;}
};


int main()
{
    Divisor *D = new Divisor();
    int q,m, a,b;
    cin>>n>>q;
    //scanf("%d", &n);
    t = new int[n*4];
    lazy = new int[n*4];
    for(int i=0; i<n*4; i++){   t[i] = 0; lazy[i] = 0; }

    for (int i = 0; i < n; ++i) scanf("%d", &t[n+i]);
    build();
    while(q--){
        cin>>m>>a>>b;
        if(m==1){  // replace  
            for(int i=n+a; i<=n+b; i++){
                int temp123 = t[i];
                t[i] = D->divisor[temp123].size();
            }
            build();
        }  
        else{ 
            int s = query(a,b);
            cout<<s<<"\n";
          } // sum
    }
    
    if(!D)delete[] D;
    if(!t)delete[] t;
    if(!lazy)delete[] lazy;
    return 0;
}