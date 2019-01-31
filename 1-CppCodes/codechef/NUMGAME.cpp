#include <bits/stdc++.h>

using namespace std;

class NUMGAME{
private:
    int T;
    int64_t n;
public:
    NUMGAME(){
        scanf("%d",&T);
        while(T--){
            scanf("%I64d",&n);
            if(n&1==1){
                printf("BOB\n");
            }else
            {
                printf("ALICE\n");
            }
        }
    }
    ~NUMGAME() {}
};
int main(){
    NUMGAME numgame;
    return 0;
}