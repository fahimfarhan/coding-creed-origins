#include <bits/stdc++.h>
using namespace std;

class Soln{
private:
    int n,q, I, J;
    int T;
    int *a;//, *b;
public:
    Soln(){
        scanf("%d",&T);
        int count = 1;
        while(T--){
            //printf("")
            cout<<"Case "<<count<<":"<<endl;
            count++;
            scanf("%d %d",&n,&q);
            a = new int[n+1];
            for(int i=1; i<=n; i++){
                scanf("%d",&a[i]);
            }
            while(q--){
                scanf("%d %d",&I,&J);
                int result = INT_MAX;
                //b = new int[J-I+1];
                //int pos = 0;
                for(int i=I; i<=J;i++){
                    //b[pos] = a[i];
                    //pos++;
                    if(a[i]<result)result = a[i];
                }
                //sort(b, b+J-I+1);
                printf("%d\n",result);
                //if(!b)delete[] b;
            }
            if(!a)delete[] a;
        }

    }
    ~Soln(){
        if(!a)delete[] a;
        //if(!b)delete[] b;
    }
};

int main(int argc, char const *argv[])
{
	/* code */
	Soln soln;
	return 0;
}