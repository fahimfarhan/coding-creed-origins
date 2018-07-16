#include  <bits/stdc++.h>

using namespace std;

class SegmentTree{
private:

public:
    int n;
    int *a, *SumAt;
    SegmentTree(){
        cin>>n;
        a = new int[n];
        SumAt = new int[4*n];

        for(int i=0; i<n; i++){     cin>>a[i];  }

        for(int i=0; i<4*n; i++){ SumAt[i] = 0; }

        for(int i=n; i<2*n; i++){
            SumAt[i] = a[i-n];
        }


    }

    int build(int at, int L, int R){
        if(L==R){
            SumAt[at] = a[L];
        }
        else{
            int mid = (L+R)/2;
            build(at*2, L, mid);
            build(at*2+1, mid+1, R);
            SumAt[at] = SumAt[2*at]+SumAt[2*at+1];
        }
        return 0;
    }

    void build2(){
        for(int i=n-1; i>=0; i--){
            SumAt[i] = SumAt[2*i]+SumAt[2*i+1];
        }
    }

    ~SegmentTree(){
        if(!a)delete[] a;
        if(!SumAt)delete[] SumAt;
    }
};

int main()
{
    SegmentTree st;
    st.build(1,1,7);
    
    for(int i=0; i<2*st.n; i++){
        cout<<"SumAt["<<i<<"]= "<<st.SumAt[i]<<",\n";
    }
    return 0;
}