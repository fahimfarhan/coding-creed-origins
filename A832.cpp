#include<bits/stdc++.h>

using namespace std;

class A832{
private:
    int64_t n,k;
public:
    A832(){
        scanf("%I64d %I64d",&n,&k);
        int64_t d = n/k;
        if(d%2==0){
            printf("NO\n");
        }else{ printf("YES\n"); }
    }
    ~A832() {}
};
int main()
{
    A832 a832;
    return 0;
}