#include <bits/stdc++.h>

using namespace std;

class B841{
private:
    int n,a;
public:
    B841(){
        scanf("%d", &n);
        for(int i=0; i<n;i++){
            scanf("%d",&a);
            if(a&1==1){
                //ie, a is odd
                printf("First\n");
                exit(0);
            }
        }
        printf("Second\n");
    }
    ~B841(){}// {if(!a)delete[] a;}
};
int main()
{
    B841 b841;
    return 0;
}