#include<bits/stdc++.h>
using namespace std;
#define si(N) scanf("%d",&N)
class A346{
private:
    int n,a,x,y;
public:
    A346(){
        x=0; y=0;
        scanf("%d",&n);
        for(int i=0; i<n; i++){
            si(a);
            x = max(x,a);
            y=__gcd(y,a);
        }

        if((x/y-n)%2){
            printf("Alice\n");
        }else printf("Bob\n");
    }
    ~A346(){}
};

int main()
{
    A346 a346;
    return 0;
}
