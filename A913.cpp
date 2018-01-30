#include <bits/stdc++.h>

using namespace std;

class A913{
private:
    int64_t n,m;
public:
    A913(){
        scanf("%I64d %I64d",&n,&m);
        double t = log2(m);
        if(n<=t){
            int64_t temp = 1 << n;
            temp = temp - 1;
            m = m & temp;
        }
        //if(n>m)
        printf("%I64d\n",m); 
    }
    ~A913() {}
};
int main()
{
    A913 a913;
    return 0;
}
