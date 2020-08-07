#include <bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d",&x)
#define sf(x) scanf("%f",&x)

#define pi(x) printf("%d\n",x)
#define pf(x) printf("%.4f\n",x)

#define ll long long 

class Soln{
private:
    int n,k,a1,a2, remaining_time;
public:
    Soln(){
        si(n); si(k);
        remaining_time = 240-k;
        a1 = 0; a2 = 0;

        try{a1 = (-5+sqrt(25 - 40*remaining_time))/20;}
        catch(exception& x){}

        try{a2 = (-5-sqrt(25 - 40*remaining_time))/20;}
        catch(exception& x){}
        int ans = max(a1,a2);
        pi(ans);
    }
    ~Soln(){}
};

int main(int argc, char const *argv[])
{
	/* code */
	Soln soln;
	return 0;
}