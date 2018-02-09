#include <bits/stdc++.h>
using namespace std;

class Soln{
private:
    int n,l,r, T;
    
public:
    Soln(){
        scanf("%d",&T);
        while(T--){
            scanf("%d",&n);
            int time = 1;
            for(int i=0; i<n; i++){
                scanf("%d %d",&l,&r);
                if(time>r){
                    printf("0 ");
                }else if(time>=l && time <=r){
                    printf("%d ",time);
                    time++;
                }else {
                    printf("%d ",l);
                    time=l+1;
                }
            }  
            printf("\n");  
        }
    }
    ~Soln(){
        
    }
};

int main(int argc, char const *argv[])
{
	/* code */
	Soln soln;
	return 0;
}