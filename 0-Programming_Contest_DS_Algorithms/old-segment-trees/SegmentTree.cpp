#include <bits/stdc++.h>

using namespace std; 

class SegmentedTree{
private:
    int *sum, *num;
public:
    void build(int at, int L, int R){
        sum[at]=0;
        if(L==R){
            //may need to do sth like
            // sum[at] = num[L]
            return;
        }
        int mid = (L+R)/2;
        build(at*2, L, mid);
        build(at*2+1, mid+1, R);
        sum[at] = sum[at*2]+sum[at*2+1];
    }

    void update(int at, int L, int R, int pos, int u){
        if(L==R){
            sum[at]+=u;
            return;
        }

        int mid = (L+R)/2;
        if(pos<=mid)
            update(at*2, L, mid, pos, u);
        else
            update(at*2+1, mid+1, R, pos, u);
    
        sum[at] = sum[at*2]+sum[at*2+1];
    }

    int query(int at, int L, int R, int l, int r){
        if(r<L || R<l) return 0;
        if(l<=L && R<=r) return sum[at];

        int mid = (L+R)/2;
        int x = query(at*2, L, mid, l, r);
        int y = query(at*2+1, mid+1,R, l, r);
        return (x+y);

    }

    
    SegmentedTree(){
        int N=100;
        sum = new int[4*N];
        num = new int[4*N];


    }

    ~SegmentedTree(){
        if(!sum)delete[] sum;
        if(!num)delete[] num;
    }
};
int main()
{

    return 0;
}