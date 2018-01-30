#include <bits/stdc++.h>

using namespace std;

class RECTANGL{
private :
    int T;
    int A[4];
public :
    RECTANGL(){
        scanf("%d",&T);
        while(T--){
            for(int i=0; i<4;i++){
                scanf("%d",&A[i]);
            }
            sort(A,A+4);
            if(A[0]==A[1] && A[2]==A[3]){
                printf("YES\n");
            }
            else{  
                printf("NO\n");
            }
        }
    } 
    ~RECTANGL(){}
};
int main()
{
    RECTANGL rectangl;
    return 0;
}