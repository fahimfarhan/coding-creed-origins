#include <bits/stdc++.h>

using namespace std;

/*
    1+a+a2+...+a5=?
*/
class bigsum{
private:
public:
    bigsum(){}
    ~bigsum(){}

    int BigSum(int a,int b, int M){
        int A = (a*a)%M;
        if(b==0) return 1%M;
        if(b==1) return A;

        if(b%2==0) return 2*BigSum(A,b/2,M);
        else if(b%2==1) return (BigSum(A,b/2,M) + a*BigSum(A,b/2,M))%M;
        return 0;
    }

};
int main()
{
    bigsum bs;
    cout<<bs.BigSum(10,5,100)<<endl;
    return 0;
}