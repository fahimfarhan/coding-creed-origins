#include <bits/stdc++.h>

using namespace std;

class Combinatorics{
private:
    int n;
public:
    Combinatorics(){
        cout<<"Enter n: ";
        cin>>n;

        int result5=0, result2=0, t5=n/5, t2=n/2;
        while(t5>0){
            result5+=t5;
            t5/=5;
        }
        
        while(t2>0){
            result2+=t2;
            t2/=2;
        }

        int result = min(result2, result5);
        cout<<result<<endl;

    }
    ~Combinatorics(){}
};

int main()
{
    Combinatorics c;
    return 0;
}