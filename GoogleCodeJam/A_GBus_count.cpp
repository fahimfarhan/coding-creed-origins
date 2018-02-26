#include <bits/stdc++.h>

using namespace std; 

class A
{
private:
    int T, n,p,c, result, *a, *b, Case;
public:
    A(){
        Case = 0;
        scanf("%d",&T);
        while(T--){
            Case++;
            scanf("%d",&n);
            a = new int[n+1];
            b = new int[n+1];
            for(int i=1; i<=n; i++){
                scanf("%d %d",&a[i],&b[i]);
            }

            scanf("%d", &p);
            printf("Case #%d:",Case);
            while(p--){
                result = 0;
                scanf("%d",&c);
                for(int i=1; i<=n; i++){
                    if(a[i]<=c && c<=b[i]) result++;
                }   
                printf(" %d", result);
            }
            printf("\n");
            clear();
        }
    }

    void clear(){
        if(!a)delete[] a;
        if(!b)delete[] b;
    }
    ~A(){
        clear();
    }
};

int main()
{
     //clock_t tStart = clock();
       /* Do your stuff here */
       
    A a;
    //printf("Time taken: %.4fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}