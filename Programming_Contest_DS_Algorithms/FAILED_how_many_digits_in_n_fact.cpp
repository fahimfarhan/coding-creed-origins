#include <bits/stdc++.h>

using namespace std;

class Combinatorics{
private:
    int n, result;
public:
    Combinatorics(){
        cout<<"Enter n: ";
        cin>>n;
        result = 0;
        for(int i=1; i<=n; i++){
            result = result + log10(i);
        }

        cout<<n<<"! digit num = "<<result<<endl;
    }
    ~Combinatorics(){}
};
int main()
{
    Combinatorics c;
    return 0;
}