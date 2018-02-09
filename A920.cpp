#include <bits/stdc++.h>
using namespace std;

class Soln{
private:
    int n,k, T, *a, max;
public:
    Soln(){
        scanf("%d",&T);
        while(T--){
            scanf("%d %d",&n,&k);
            a = new int[k];
            for(int i=0; i<k; i++){
                scanf("%d",&a[i]);
            }
            max=0;
            int first = a[0];
            int last = n-a[k-1]+1;
            for(int i=01; i<k; i++){
                if( (a[i]-a[i-1]+1) > max) max = a[i]-a[i-1]+1; // if( (a[i]-a[i-1]+2) > max) max = a[i]-a[i-1]+2; 
            }
            if(max&1){ max = (max+1)/2;}
            else{ max = max/2; }

            if(max<first) max=first;
            if(max<last) max=last;

            printf("%d\n",max);
            
            /*if(max>first && max>last){
                printf("%d")
            }*/
        }
    }
    ~Soln(){if(!a)delete[] a; }
};

int main(int argc, char const *argv[])
{
	/* code */
	Soln soln;
	return 0;
}