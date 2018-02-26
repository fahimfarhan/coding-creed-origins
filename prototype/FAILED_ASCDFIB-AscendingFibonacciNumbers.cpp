#include <bits/stdc++.h>

using namespace std;

class Fib{
private:
    int T,a,b, Case;
    int *f;
    int *copy;
public:
    Fib(){
        scanf("%d",&T);
        f = new int[100000+110];
        f[0]=0;
        f[1]=0;
        f[2]=1;
        for(int i=3; i<(100110); i++){
            f[i] = (f[i-1]+f[i-2])%100000;
        }
        //sort(f,f+100110);
        Case=0;
        while(T--){
            Case++;
            scanf("%d %d",&a,&b);
            int last;
            if(b>100){last = a+100;}else{ last = a+b;}
            copy = new int[last-a+1];
            for(int i=0; i<last-a+1;i++ ){
                copy[i] = f[a+i];
            }
            sort(copy, copy+last-a+1);
            printf("Case %d:",Case);
            for(int i=0; i<last-a+1; i++){
                printf(" %d",copy[i]);
            }printf("\n");
            if(!copy)delete[] copy;
        }
    }

    ~Fib(){
        if(!f)delete[] f;
        if(!copy)delete[] copy;
    }
};

int main()
{
    Fib fib;
    return 0;
}