#include <bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d",&x)
#define sf(x) scanf("%f",&x)

#define pi(x) printf("%d\n",x)
#define pf(x) printf("%f\n",x)

class Soln{
private:
    int n, count;
public:
    Soln(){
        count = 0;
        si(n);
        for(int i=1; i<=n/2; i++){
            int L=i, M=(n-i)/i;
            if( (L+M*L) == n ){
                count++;
            } 
        }
        pi(count);
    }
    ~Soln(){}
};



int main(int argc, char const *argv[])
{
	/* code */
	Soln soln;
	return 0;
}