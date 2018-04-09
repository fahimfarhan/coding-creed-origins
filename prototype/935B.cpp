#include <bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d",&x)
#define sf(x) scanf("%f",&x)

#define pi(x) printf("%d\n",x)
#define pf(x) printf("%f\n",x)

class Soln{
private:
    int n, x,y,count; //, prev, curr, xp,yp;
    string s;
public:
    Soln(){
        x=0;y=0;
        //prev = 0; curr=0;
        count = 0;
        si(n);
        cin>>s;
        for(int i=0; i<n-1; i++){
            if(s[i]=='U'){ y++; }
            else { x++; }
            if((x==y) && (s[i]==s[i+1])){
                count++;
            }
        }

        pi(count);

    }

    /*bool sameKingdom(){
        if(prev>0 && )
    }*/
    ~Soln(){}
};

int main(int argc, char const *argv[])
{
	/* code */
	Soln soln;
	return 0;
}