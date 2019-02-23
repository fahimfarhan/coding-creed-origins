#include <bits/stdc++.h>

using namespace std;

class C913{
private:
    int n;
    int64_t L, *c;
    double r;
    vector< pair<float,pair<int64_t, int> > > A;
    int d;
public:
    C913(){
        scanf("%d %I64d",&n,&L);
        c = new int64_t[n];
        //r = new double[n];
        for(int i=0; i<n; i++){
            scanf("%I64d",&c[i]);
        }
        d = 1;
        for(int i=0; i<n; i++){
            r = c[i]/d;
            A.push_back(make_pair(r,make_pair(c[i],d)));
            d=d<<1;
        }
        sort(A.begin(),A.end());

        int64_t cost = 0;
        int i = 0;
         while (L > 0)
        {
            
        }


    }
    ~C913() {
        if(!c)delete[] c;
    }
};
int main()
{
    C913 c913;
    return 0;
}