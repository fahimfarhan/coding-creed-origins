#include <iostream>
#define EAT 1
#define JUMP 1
using namespace std;

class B265{
private:
    int n, ans, *A;
public:
    B265(){
        ans = 0;

        cin>>n;
        A = new int[n];
        for(int i=0; i<n; i++){
            cin>>A[i];
        }
        ans = A[0]+EAT;
        for(int i=1; i<n; i++){
            if(A[i]>=A[i-1]){
                ans = ans+JUMP+A[i]-A[i-1]+EAT;
            }else{
                ans = ans+A[i-1]-A[i]+JUMP+EAT;
            }

            
        }
        cout << ans << endl;
    }
    ~B265() {if(!A)delete[] A;}
};

int main()
{
    B265 b265;
    return 0;
}