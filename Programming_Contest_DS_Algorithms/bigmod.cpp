#include <bits/stdc++.h>

using namespace std;

/*
    (ab) mod M = (a mod M)(b mod M) mod M
    (a^b) mod M = ?
    x1 = b/2, x2 = b-x1
    so, ? = (a^x1 mod M)(a^x2 mod M) mod M
*/
class BigMod{
 public:
    BigMod(){}
    ~BigMod(){}
    int bigMod(int a, int M){
        if(a<M) return a%M;
        int x1 = a/2;
        int x2 = a-x1;
        return (bigMod(x1,M)*bigMod(x2,M))%M;

    }

    int bigMod(int a, int pow, int M){  
        if(pow==0) return 1%M;
        if(pow==1) return a%M;
        int x1 = pow/2;
        int x2 = pow-x1;
        return (bigMod(a,x1,M)*bigMod(a,x2,M))%M;
    }    
};


int main()
{
    BigMod b;
    cout<<b.bigMod(1000,97)<<endl;
    cout<<b.bigMod(91,1000,97)<<endl;
    
    return 0;
}