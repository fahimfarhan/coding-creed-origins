#include <bits/stdc++.h>
using namespace std;

class B914{
private:
    int n, count;
    int *a;
public:
    B914(){

        scanf("%d",&n);
        a = new int[n];
        for(int i=0; i<n; i++){
            scanf("%d", &a[i]);
        }

        sort(a,a+n);
        int max = a[n-1];
        count = 0;
        for(int i=n-1; i>=0; i--){
            if(a[i]!=max){ break;}
            count++;
        }
        if(count%2==1){
            printf("Conan\n");
            
        }else{
            if(count<n){
                printf("Conan\n");
            }else if(count==n){
                printf("Agasa\n");
            }
            
        }
    }
    ~B914() {if(!a)delete[] a;}
};
int main(int argc, char const *argv[])
{
    /* code */

    B914 b914;
    return 0;
}