#include <bits/stdc++.h>

using namespace std;

class A946{
private:
    int a,n,B,C;
public:
    A946(){
        B=0; C=0;
        scanf("%d",&n);
        for(int i=0; i<n; i++){
            scanf("%d",&a);
            if(a>=0){B+=a;}
            else{ C+=a;}
        }

        a = B-C;
        printf("%d\n",a);
    }
};

int main()
{
    A946 a946;
    return 0;
}